#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"



void CMIS::addTrain(const Train& newTrain)
{
	ofstream fout;
	fout.open("trainsinfo.txt", ios::out);
	if (!fout) {
		cout << "�޷����ļ�\n";
		return;
	}

	trainsinfo.push_back(newTrain);		//��ӳ�����Ϣ

	fout << newTrain << endl;
	fout.close();
}

	void CMIS::loadTrainInfo() {
		ifstream fin("trainsinfo.txt", ios::in);
		if (!fin) {
			cout << "�޷����ļ�\n";
			return;
		}
		Train tempTrain;
		while (fin >> tempTrain) {
			trainsinfo.push_back(tempTrain);
		}
		fin.close(); // �ر��ļ�
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

	void CMIS::addUser(const User& newUser)
	{
		ofstream fout;
		fout.open("usersinfo.txt", ios::out);
		if (!fout) {
			cout << "�޷����ļ�\n";
			return;
		}

		users.push_back(newUser);
		fout << newUser << endl;
		fout.close();
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
			users.push_back(user);
		}

		fin.close(); // �ر��ļ���
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


	void CMIS::buyTicket(Ticket& newTicket) // ��Ʊ
	{
		fstream fout;
		fout.open("tickets.txt", ios::out);
		if (!fout) {
			cout << "�޷����ļ�\n";
			return;
		}

		User* passenger = findUser(newTicket.getPassengerName());

		//����Ʊ��
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

		tickets.push_back(newTicket);	//��ӹ�Ʊ��Ϣ
		fout << newTicket << endl;		//����Ʊ��Ϣ�����ļ���
	}


	void CMIS::refundTicket(string passengername, string trainnumber, string traveldate, string refunddate, string refundtime)// ��Ʊ
	{
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


	void CMIS::ShowSoldTickets()
	{
		int count = 1;

		for (vector<Ticket>::iterator pt = tickets.begin(); pt != tickets.end(); pt++)
		{
			cout << count++ << " " << *pt << endl;
		}
	}