#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<string>
#include<vector>
#include<cmath>
#include<fstream>

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
	Train(){}
	Train(string _number,string _time,string _begincity,string _endcity,double _ticketprice)
		:trainnumber(_number),traveltime(_time),begincity(_begincity),endcity(_endcity),ticketprice(_ticketprice){}
	string gettrainnumber() const{ return trainnumber; }
	double getticketprice() const{ return ticketprice; }

	friend istream& operator>>(istream& is, Train& t) {
		is >> t.trainnumber >> t.traveltime >> t.begincity >> t.endcity >> t.ticketprice;
		return is;
	}
	friend ostream& operator<<(ostream& os, Train& t) {
		os << t.trainnumber <<" " << t.traveltime <<" " << t.begincity << " " << t.endcity << " " << t.ticketprice;
		return os;
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
	int getIdType()
	{
		if (this != nullptr)
			return idtype;
	}
	friend ostream& operator<<(ostream& out,const User& user)
	{
		out << user.name << " " << user.gender << " " << user.idnumber << " "<<user.idtype;
		return out;
	}
	friend istream& operator>>(istream& is, User& u)
	{
		is >> u.name >> u.gender>> u.idnumber  >> u.idtype;
		return is;
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
	double price=0;
public:
	Ticket(){}
	Ticket(string _passengername, string _trainnumber, string _traveldate, string _buydate, string _buytime) :
		passengername(_passengername), trainnumber(_trainnumber), traveldate(_traveldate), buydate(_buydate), buytime(_buytime) {}

	string getPassengerName() { return passengername; }
	string getTrainNumber() { return trainnumber; }
	int getSeatLevel() { return seatlevel; }
	string getTravelDate() { return traveldate; }
	string getBuyDate() { return buydate;}
	string getBuyTime() { return buytime; }
	void setPrice(double _price) { price = _price; }
	
	friend ostream& operator<<(ostream& out, Ticket t)
	{
		out << t.passengername <<" "<< t.trainnumber <<" "<< t.seatlevel <<" " << t.traveldate <<" " << t.buydate <<" " << t.buytime;
		return out;
	}
	friend istream& operator>>(istream& is, Ticket& t)
	{
		is >> t.passengername >> t.trainnumber >> t.seatlevel >> t.traveldate >> t.buydate >> t.buytime;
		return is;
	}
};


class CMIS
{
private:
	std::vector<User> users;		//����˿���Ϣ
	vector<Ticket> tickets;
	vector<Train> trainsinfo;		//������Ϣ
public:
	CMIS()
	{
		//loadTrainInfo();		//���س�����Ϣ
		//loadUsers();
	}

	void addTrainsInfo()		//��ӳ�����Ϣ
		//loadTickets();
		
		
	{

		ofstream fout;
		fout.open("trainsinfo.txt", ios::out);
		if (!fout) {
			cout << "�޷����ļ�\n";
			return;
		}

		int command;
		Train newTrain;
		while (true)
		{
			if (cin >> command)
			{
				if (command == 1)
				{
					if (cin >> newTrain) {
						trainsinfo.push_back(newTrain);
						fout << newTrain << endl;
					}
				}
				if (command == 0)	//�����ã�������������������������������������������
				{
					return;
				}
			}
			else if (cin.eof())
			{
				cout << "������Ϣ�������\n";
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
			}
		}
		fout.close();
	}

	void loadTrainInfo() {
		ifstream fin("trainsinfo.txt", ios::in); // ���ļ��Զ�ģʽ
		if (!fin) {
			cout << "�޷����ļ�\n";
			return;
		}
		Train tempTrain;
		while (fin >> tempTrain) { // ����֮ǰ����������������������ȡ
			trainsinfo.push_back(tempTrain);
		}
		fin.close(); // �ر��ļ�
	}


	void registerUser()		//����û�ע����Ϣ
	{
		ofstream fout;
		fout.open("usersinfo.txt", ios::out);
		if (!fout) {
			cout << "�޷����ļ�\n";
			return;
		}

		int command;
		User newUser;
		
		while (true)
		{
			if (cin.eof()) break;
			if (cin >> command)
			{
				if (command == 2)
				{
					if (cin >> newUser)
						users.push_back(newUser);
						fout << newUser << endl;
				}
				if (command == 0)	//�����ã�������������������������������������������
				{
					return;
				}
			}
			else if (cin.eof())
			{
				cout << "�û�ע����ϣ�\n";
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
			}
		}
		fout.close();
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
		for (vector<Train>::iterator pt = trainsinfo.begin(); pt != trainsinfo.end();pt++)		//����trainsinfo
		{
			if (pt->gettrainnumber() == _trainnumber)
			{
				return  pt->getticketprice();
			}
		}
	}

	void loadTickets()
	{
		ifstream fin;
		fin.open("tickets.txt", ios::in); // ��Ʊ����Ϣ�ļ�

		if (!fin)
		{
			cout << "�޷���Ʊ����Ϣ�ļ�\n";
			return;
		}

		Ticket ticket;
		// ��ȡ�ļ��е�ÿһ��ֱ���ļ�����
		while (fin >> ticket)
		{
			tickets.push_back(ticket);
		}

		fin.close(); // �ر��ļ���
	}

	void loadUsers() {
		std::ifstream fin;
		fin.open("userinfo.txt", std::ios::in); // ���û���Ϣ�ļ�

		if (!fin) {
			std::cout << "�޷����û���Ϣ�ļ�\n";
			return;
		}

		User user;
		while (fin >> user) {  // ��ȡ�û���Ϣֱ���ļ�ĩβ
			users.push_back(user); // ���û���ӵ�������
		}

		fin.close(); // �ر��ļ���
	}

	void buyTicket()
	{
		fstream fout;
		fout.open("tickets.txt", ios::out);
		if (!fout) {
			cout << "�޷����ļ�\n";
			return;
		}

		int command;
		Ticket newTicket;

		while (true)
		{
			if (cin >> command)
			{
				if (command == 3)
				{
					if (cin >> newTicket)
					{
						User* passenger = findUser(newTicket.getPassengerName());

						double ticketPrice = findTrainPrice(newTicket.getTrainNumber());		//�ҵ���Ӧ����Ʊ��
						double discount = 1.0;
						if (newTicket.getSeatLevel() == 2)
						{
							switch (passenger->getIdType())
							{
							case 1:discount = 0.3; break;
							case 2:discount = 0.5; break;
							}
						}
						double finalPrice = ticketPrice * discount;
						newTicket.setPrice(finalPrice);

						tickets.push_back(newTicket);
						fout << newTicket <<endl;		//����Ʊ��Ϣ�����ļ���
					}
				}
				if (command == 0)	//�����ã�������������������������������������������
				{
					return;
				}
			}
			else if (cin.eof()) 
			{ 
				cout << "��Ʊ������ϣ�\n";
				break; 
			}
			else
			{
				cin.clear();  // �������״̬
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
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
		
		while (true)
		{
			if (cin >> command)
			{
				if (command == 4)
				{
					//���㲢�۳���Ʊ���ø��û�����д)

					cin >> passengername >> trainnumber >> traveldate >> refunddate >> refundtime;
					for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end();)
					{
						if (pt->getPassengerName() == passengername && pt->getTrainNumber() == trainnumber) //�ҵ�����ɾ����������Ʊ��¼
						{
							pt = tickets.erase(pt); // ʹ��erase�ķ���ֵ���µ�����
						}
						else
						{
							++pt; // ���������ƶ�����һ��Ԫ��
						}
					}
				}
				if (command == 0)	//�����ã�������������������������������������������
				{
					return;
				}
			}
			else if (cin.eof())  // ������ǵ������ļ�ĩβ
			{
				cout << "��Ʊ��ϣ�\n";
				break;  // �˳�����
			}
			else  // ���������������������������
			{
				cin.clear();  // �������״̬
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
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


