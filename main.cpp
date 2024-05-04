

#include"my12306.h"


int main() {

    CMIS cmis;

    // ��ӳ�����Ϣ
   

	int command;
	Train newTrain;
	while (true)
	{
		if (cin >> command)
		{
			if (command == 1)
			{
				if (cin >> newTrain)
				{
					cmis.addTrain(newTrain);		//��ӳ�����Ϣ
				}
			}
		}
		// ���cin������EOF״̬�����磬�û�������Ctrl+Z���������
		else if (cin.eof()) {
			// ���failbit��eofbit
			std::cin.clear();
			cout << "������Ϣ�������\n";
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
		}
	}


    // ע���û�
    cout << "��ʼ�û�ע�������" << endl;

	User newUser;

	while (true)
	{
		if (cin >> command)
		{
			if (command == 2)
			{
				if (cin >> newUser)
				{
					cmis.addUser(newUser);
				}
			}
		}
		else if (cin.eof())
		{
			std::cin.clear();
			cout << "�û�ע����ϣ�\n";
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
		}
	}


    // ��Ʊ
    cout << "��ʼ��Ʊ������" << endl;

	Ticket newTicket;

	while (true)
	{
		if (cin >> command)
		{
			if (command == 3)
			{
				if (cin >> newTicket)
				{
					cmis.buyTicket(newTicket);		//��ӹ�Ʊ��Ϣ
				}
			}
		}
		else if (cin.eof())
		{
			std::cin.clear();
			cout << "��Ʊ������ϣ�\n";
			break;
		}
		else
		{
			cin.clear();  // �������״̬
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
		}
	}


    // ��Ʊ
		cout << "��ʼ��Ʊ������" << endl;
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
					cmis.refundTicket(passengername, trainnumber, traveldate, refunddate, refundtime);// ��Ʊ
				}
			}
			else if (cin.eof())  
			{
				cin.clear();
				std:: cout << "��Ʊ��ϣ�\n";
				break;  
			}
			else  // ����������������
			{
				cin.clear(); 
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // ���Դ�������ֱ����һ�����з�
			}
		}
    // ��ʾ����Ʊ
    cout << "��ʾ�������۳���Ʊ��" << endl;
    cmis.ShowSoldTickets();

    return 0;
}