#define _CRT_SECURE_NO_WARNINGS
#ifndef MY12306_H
#define MY12306_H



#include<iostream>
#include<string>
#include<vector>
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
	friend ostream& operator<<(ostream& os, const Train& t) {
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
	Ticket(string _passengername, string _trainnumber, string _traveldate, string _buydate, string _buytime) :passengername(_passengername), trainnumber(_trainnumber), traveldate(_traveldate), buydate(_buydate), buytime(_buytime) {}

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
	vector<Ticket> tickets;			//��Ʊ��Ϣ
	vector<Train> trainsinfo;		//������Ϣ
public:
	CMIS(){}
	void addTrain(const Train& train); // ��ӳ���
	void addUser(const User& user); // ע���û�
	void buyTicket(Ticket& ticket); // ��Ʊ
	void refundTicket(string passengername,string trainnumber,string traveldate,string refunddate,string refundtime); // ��Ʊ
	void ShowSoldTickets(); // ��ʾ����Ʊ�ļ�¼


	void loadTrainInfo();
	double findTrainPrice(string _trainnumber);
	void loadTickets();
	void loadUsers();
	User* findUser(string _name);
	
};


#endif