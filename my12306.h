#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<cmath>

using namespace std;





class Train
{
protected:
	string trainnumber;
	string traveltime;
	string begincity;
	string endcity;
	double ticketprice;
public:
	Train(string _number,string _time,string _begincity,string _endcity,double _ticketprice)
		:trainnumber(_number),traveltime(_time),begincity(_begincity),endcity(_endcity),ticketprice(_ticketprice){}
	string gettrainnumber() const{ return trainnumber; }
	double getticketprice() const{ return ticketprice; }
};

class Admin			//����Ա
{
private:
	vector<Train> trainsinfo;		//������Ϣ
public:
	

	Admin(){}
	const vector<Train>& getTrainsInfo() { return trainsinfo; }
	void addTrainInfo()		//��ӳ�����Ϣ
	{
		string number, time, begincity, endcity;
		int command;
		double ticketprice;
		while (cin >> command >> number >> time >> begincity >> endcity >> ticketprice)
		{
			if (command == 1)
			{
				Train newtrain(number, time, begincity, endcity, ticketprice);
				trainsinfo.push_back(newtrain);
			}
		}
	}
};


class User
{
protected:
	string name;
	int gender;
	string idnumber;	//���֤��
	int idtype;			//�������(����(1)��ѧ��(2)����ͨ����(3))

public:
	User(){}
	User(string _name,int _gender,string _idnumber,int _idtype):name(_name),gender(_gender),idtype(_idtype){}
	void displayInfo()
	{
		cout << name;
	}
	string getName() { return name; }
	int getGender() { return gender;}
	string getIdnumber(){return idnumber;}
	int getIdType() { return idtype; }
	
	friend ostream& operator<<(ostream& out,const User& user)
	{
		out << user.name;
	}
	friend bool operator==(User a, User b)		//�ж�user���Ƿ����
	{
		if (a.name == b.name && a.gender == b.gender && a.idnumber == b.idnumber)
			return true;
		else
			return false;
	}
};


class Ticket
{
protected:
	string passengername;
	string trainnumber;		//����
	int seatlevel;     //��λ�ȼ�(һ����(1)��������(2))
	string traveldate;
	string buydate;
	string buytime;
public:
	Ticket(string _passengername, string _trainnumber, string _traveldate, string _buydate, string _buytime) :
		passengername(_passengername), trainnumber(_trainnumber), traveldate(_traveldate), buydate(_buydate), buytime(_buytime) {}

	string getPassengername() { return passengername; }
	string getTrainnumber() { return trainnumber; }
	
	friend ostream& operator<<(ostream& out, const Ticket ticket)
	{
		out << ticket.passengername << ticket.trainnumber << ticket.seatlevel << ticket.traveldate << ticket.buydate << ticket.buytime;
		return out;
	}
};






class UserManager
{
private:
	std::vector<User> users;		//����˿���Ϣ
	vector<Ticket> tickets;
	Admin& admin;		//���泵����Ϣ
public:
	UserManager(Admin& _admin):admin(_admin) {}
	void registerUser()		//����û�ע����Ϣ
	{
		string name, idnumber;
		int gender, idtype,command;
		while (cin >> command >> name >> idnumber >> gender >> idtype)
		{
			if (command == 2)
			{
				User newuser(name, gender, idnumber, idtype);
				users.push_back(newuser);
			}
		}
	}
	User* findUser(string _name)		//Ѱ��ָ��user,���ص�ַ
	{
		for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
		{
			if (i->getName()==_name)
				return &(*i);
		}
		return nullptr;
	}

	double findTrainPrice(string _trainnumber)
	{
		const vector<Train>& trainsinfo = admin.getTrainsInfo();
		for ( const Train& curtrain : trainsinfo)		//����trainsinfo
		{
			if (curtrain.gettrainnumber() == _trainnumber)
			{
				return  curtrain.getticketprice();
			}
		}
	}
	void buyTicket()
	{
		int command;
		string passengername;	//
		int seatlevel;
		string trainnumber;
		string traveldate;
		string buydate;
		string buytime;

		
		User* passenger = findUser(passengername);

		while (cin >> command >> passengername >> trainnumber >> seatlevel >> traveldate >> buydate >> buytime)
		{
			if (command == 3)
			{

				double ticketPrice = findTrainPrice(trainnumber);		//�ҵ���Ӧ����Ʊ��
				double discount = 1.0;
				if (seatlevel == 2)
				{
					switch (passenger->getIdType())
					{
					case 1:discount = 0.3; break;
					case 2:discount = 0.5; break;
					}
				}
				double finalPrice = ticketPrice * discount;

				Ticket newTicket(passengername, trainnumber, traveldate, buydate, buytime);
				tickets.push_back(newTicket);
			}

			
		}
	}

	void refundTicket()
	{
		int command;
		string passengername;	
		string trainnumber;
		string traveldate;
		string refunddate;
		string refundtime;

		while (cin >> command >> passengername >> trainnumber >> traveldate >> refunddate >> refundtime)
		{
			if (command == 4)
			{
				//���㲢�۳���Ʊ���ø��û�����д��
				

				for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end(); pt++)
				{
					if (pt->getPassengername() == passengername && pt->getTrainnumber() == trainnumber)		//�ҵ�����ɾ����������Ʊ��¼
					{
						tickets.erase(pt);
					}
				}
			}
		}

	}

	void ShowSoldTickets()
	{
		int count = 1;
		for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end(); pt++)
		{
			cout << count++ << " " << *pt << endl;
		}
	}
};


