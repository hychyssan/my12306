

#include"my12306.h"


int main() {

    CMIS cmis;

    // 添加车次信息
   

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
					cmis.addTrain(newTrain);		//添加车次信息
				}
			}
		}
		// 如果cin进入了EOF状态（例如，用户按下了Ctrl+Z），清除它
		else if (cin.eof()) {
			// 清除failbit和eofbit
			std::cin.clear();
			cout << "车次信息输入完毕\n";
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
		}
	}


    // 注册用户
    cout << "开始用户注册操作：" << endl;

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
			cout << "用户注册完毕！\n";
			break;
		}
		else
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
		}
	}


    // 购票
    cout << "开始买票操作：" << endl;

	Ticket newTicket;

	while (true)
	{
		if (cin >> command)
		{
			if (command == 3)
			{
				if (cin >> newTicket)
				{
					cmis.buyTicket(newTicket);		//添加购票信息
				}
			}
		}
		else if (cin.eof())
		{
			std::cin.clear();
			cout << "车票购买完毕！\n";
			break;
		}
		else
		{
			cin.clear();  // 清除错误状态
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
		}
	}


    // 退票
		cout << "开始退票操作：" << endl;
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
					cmis.refundTicket(passengername, trainnumber, traveldate, refunddate, refundtime);// 退票
				}
			}
			else if (cin.eof())  
			{
				cin.clear();
				std:: cout << "退票完毕！\n";
				break;  
			}
			else  // 如果出现了输入错误
			{
				cin.clear(); 
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  // 忽略错误输入直到下一个换行符
			}
		}
    // 显示已售票
    cout << "显示所有已售出的票：" << endl;
    cmis.ShowSoldTickets();

    return 0;
}