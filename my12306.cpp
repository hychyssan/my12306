#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"




	void CMIS::addTrainsInfo()		//��ӳ�����Ϣ
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
			// ���cin������EOF״̬�����磬�û�������Ctrl+Z���������
			else if (cin.eof()) {
				// ���failbit��eofbit
				std::cin.clear();
				// ������������ʣ����ַ���ֱ����һ�����з�
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

	void CMIS::loadTrainInfo() {
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


	void CMIS::registerUser()		//����û�ע����Ϣ
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
				// ���failbit��eofbit
				std::cin.clear();
				// ������������ʣ����ַ���ֱ����һ�����з�
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

	User* CMIS::findUser(string _name)		//Ѱ��ָ��user,���ص�ַ
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
		for (vector<Train>::iterator pt = trainsinfo.begin(); pt != trainsinfo.end(); pt++)		//����trainsinfo
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

	void CMIS::loadUsers() {
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

	void CMIS::buyTicket()
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
						fout << newTicket << endl;		//����Ʊ��Ϣ�����ļ���
					}
				}
				if (command == 0)	//�����ã�������������������������������������������
				{
					return;
				}
			}
			else if (cin.eof())
			{
				// ���failbit��eofbit
				std::cin.clear();
				// ������������ʣ����ַ���ֱ����һ�����з�
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
				// ���failbit��eofbit
				std::cin.clear();
				// ����cin�Ѿ������ã����Լ���ʹ����
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

	void CMIS::ShowSoldTickets()
	{
		int count = 1;

		for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end(); pt++)
		{
			cout << count++ << " " << *pt << endl;
		}
	}