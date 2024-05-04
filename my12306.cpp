#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"




	void CMIS::addTrainsInfo()		//添加车次信息
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
			// 如果cin进入了EOF状态（例如，用户按下了Ctrl+Z），清除它
			else if (cin.eof()) {
				// 清除failbit和eofbit
				std::cin.clear();
				// 忽略输入流中剩余的字符，直到下一个换行符
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

	void CMIS::loadTrainInfo() {
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


	void CMIS::registerUser()		//添加用户注册信息
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
				// 清除failbit和eofbit
				std::cin.clear();
				// 忽略输入流中剩余的字符，直到下一个换行符
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

	User* CMIS::findUser(string _name)		//寻找指定user,返回地址
	{
		for (vector<User>::iterator i = users.begin(); i != users.end(); i++)
		{
			if (i->getName() == _name)
				return &(*i);
		}
		return nullptr;
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

	void CMIS::loadUsers() {
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

	void CMIS::buyTicket()
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
						fout << newTicket << endl;		//将购票信息读入文件中
					}
				}
				if (command == 0)	//测试用！！！！！！！！！！！！！！！！！！！！！！
				{
					return;
				}
			}
			else if (cin.eof())
			{
				// 清除failbit和eofbit
				std::cin.clear();
				// 忽略输入流中剩余的字符，直到下一个换行符
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

	void CMIS::refundTicket()
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
				// 清除failbit和eofbit
				std::cin.clear();
				// 现在cin已经被重置，可以继续使用了
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

	void CMIS::ShowSoldTickets()
	{
		int count = 1;

		for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end(); pt++)
		{
			cout << count++ << " " << *pt << endl;
		}
	}