#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"

int main()
{
	Admin admin;
	admin.addTrainInfo();
	UserManager control(admin);

	control.registerUser();
	control.buyTicket();
	control.refundTicket();
	control.ShowSoldTickets();

	return 0;
}