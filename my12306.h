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
	string idnumber;	//身份证号
	int idtype;			//身份类型(军人(1)、学生(2)、普通居民(3))

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
	friend bool operator==(User a, User b)		//判断user类是否相等
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
	string trainnumber;		//车次
	int seatlevel;     //座位等级(一等座(1)、二等座(2))
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
	std::vector<User> users;		//保存乘客信息
	vector<Ticket> tickets;
	vector<Train> trainsinfo;		//车次信息
public:
	CMIS()
	{
		//loadTrainInfo();		//加载车次信息
		//loadUsers();
	}

	void addTrainsInfo()		//添加车次信息
		//loadTickets();
		
		
	{

		ofstream fout;
		fout.open("trainsinfo.txt", ios::out);
		if (!fout) {
			cout << "无法打开文件\n";
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
				if (command == 0)	//测试用！！！！！！！！！！！！！！！！！！！！！！
				{
					return;
				}
			}
			else if (cin.eof())
			{
				cout << "车次信息输入完毕\n";
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
			}
		}
		fout.close();
	}

	void loadTrainInfo() {
		ifstream fin("trainsinfo.txt", ios::in); // 打开文件以读模式
		if (!fin) {
			cout << "无法打开文件\n";
			return;
		}
		Train tempTrain;
		while (fin >> tempTrain) { // 利用之前定义的输入操作符重载来读取
			trainsinfo.push_back(tempTrain);
		}
		fin.close(); // 关闭文件
	}


	void registerUser()		//添加用户注册信息
	{
		ofstream fout;
		fout.open("usersinfo.txt", ios::out);
		if (!fout) {
			cout << "无法打开文件\n";
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
				if (command == 0)	//测试用！！！！！！！！！！！！！！！！！！！！！！
				{
					return;
				}
			}
			else if (cin.eof())
			{
				cout << "用户注册完毕！\n";
				break;
			}
			else
			{
				cin.clear();
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
			}
		}
		fout.close();
	}

	User* findUser(string _name)		//寻找指定user,返回地址
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
		for (vector<Train>::iterator pt = trainsinfo.begin(); pt != trainsinfo.end();pt++)		//遍历trainsinfo
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
		fin.open("tickets.txt", ios::in); // 打开票务信息文件

		if (!fin)
		{
			cout << "无法打开票务信息文件\n";
			return;
		}

		Ticket ticket;
		// 读取文件中的每一行直到文件结束
		while (fin >> ticket)
		{
			tickets.push_back(ticket);
		}

		fin.close(); // 关闭文件流
	}

	void loadUsers() {
		std::ifstream fin;
		fin.open("userinfo.txt", std::ios::in); // 打开用户信息文件

		if (!fin) {
			std::cout << "无法打开用户信息文件\n";
			return;
		}

		User user;
		while (fin >> user) {  // 读取用户信息直到文件末尾
			users.push_back(user); // 将用户添加到向量中
		}

		fin.close(); // 关闭文件流
	}

	void buyTicket()
	{
		fstream fout;
		fout.open("tickets.txt", ios::out);
		if (!fout) {
			cout << "无法打开文件\n";
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

						double ticketPrice = findTrainPrice(newTicket.getTrainNumber());		//找到对应车次票价
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
						fout << newTicket <<endl;		//将购票信息读入文件中
					}
				}
				if (command == 0)	//测试用！！！！！！！！！！！！！！！！！！！！！！
				{
					return;
				}
			}
			else if (cin.eof()) 
			{ 
				cout << "车票购买完毕！\n";
				break; 
			}
			else
			{
				cin.clear();  // 清除错误状态
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
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
					//计算并扣除退票费用给用户（待写)

					cin >> passengername >> trainnumber >> traveldate >> refunddate >> refundtime;
					for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end();)
					{
						if (pt->getPassengerName() == passengername && pt->getTrainNumber() == trainnumber) //找到符合删除条件的售票记录
						{
							pt = tickets.erase(pt); // 使用erase的返回值更新迭代器
						}
						else
						{
							++pt; // 否则正常移动到下一个元素
						}
					}
				}
				if (command == 0)	//测试用！！！！！！！！！！！！！！！！！！！！！！
				{
					return;
				}
			}
			else if (cin.eof())  // 如果我们到达了文件末尾
			{
				cout << "退票完毕！\n";
				break;  // 退出函数
			}
			else  // 如果出现了输入错误（例如非整数）
			{
				cin.clear();  // 清除错误状态
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
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


