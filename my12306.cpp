#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"



void CMIS::addTrain(const Train& newTrain)
{
	ofstream fout;
	fout.open("trainsinfo.txt", ios::out);
	if (!fout) {
		cout << "无法打开文件\n";
		return;
	}

	trainsinfo.push_back(newTrain);		//添加车次信息

	fout << newTrain << endl;
	fout.close();
}

	void CMIS::loadTrainInfo() {
		ifstream fin("trainsinfo.txt", ios::in);
		if (!fin) {
			cout << "无法打开文件\n";
			return;
		}
		Train tempTrain;
		while (fin >> tempTrain) {
			trainsinfo.push_back(tempTrain);
		}
		fin.close(); // 关闭文件
	}

	double CMIS::findTrainPrice(string _trainnumber)
	{
		for (vector<Train>::iterator pt = trainsinfo.begin(); pt != trainsinfo.end(); pt++)		//遍历trainsinfo
		{
			if (pt->gettrainnumber() == _trainnumber)
			{
				return  pt->getticketprice();
			}
		}
	}

	void CMIS::addUser(const User& newUser)
	{
		ofstream fout;
		fout.open("usersinfo.txt", ios::out);
		if (!fout) {
			cout << "无法打开文件\n";
			return;
		}

		users.push_back(newUser);
		fout << newUser << endl;
		fout.close();
	}

	void CMIS::loadUsers() {
		std::ifstream fin;
		fin.open("userinfo.txt", std::ios::in); // 打开用户信息文件

		if (!fin) {
			std::cout << "无法打开用户信息文件\n";
			return;
		}

		User user;
		while (fin >> user) {  // 读取用户信息直到文件末尾
			users.push_back(user);
		}

		fin.close(); // 关闭文件流
	}

	User* CMIS::findUser(string _name)		//寻找指定user,返回地址
	{
		for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
		{
			if (i->getName() == _name)
				return &(*i);
		}
		return nullptr;
	}




	void CMIS::loadTickets()
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


	void CMIS::buyTicket(Ticket& newTicket) // 购票
	{
		fstream fout;
		fout.open("tickets.txt", ios::out);
		if (!fout) {
			cout << "无法打开文件\n";
			return;
		}

		User* passenger = findUser(newTicket.getPassengerName());

		//计算票价
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

		tickets.push_back(newTicket);	//添加购票信息
		fout << newTicket << endl;		//将购票信息读入文件中
	}


	void CMIS::refundTicket(string passengername, string trainnumber, string traveldate, string refunddate, string refundtime)// 退票
	{
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


	void CMIS::ShowSoldTickets()
	{
		int count = 1;

		for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end(); pt++)
		{
			cout << count++ << " " << *pt << endl;
		}
	}