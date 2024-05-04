#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"

int main() {

    CMIS cmis;

    // 添加车次信息
    cmis.addTrainsInfo(); // 用户需要根据提示输入车次信息，最后使用 Ctrl+Z 结束输入

    // 注册用户
    cout << "开始用户注册操作：" << endl;
    cmis.registerUser(); 

    // 购票
    cout << "开始买票操作：" << endl;
    cmis.buyTicket();

    cmis.ShowSoldTickets();

    // 退票
    cout << "开始退票操作：" << endl;
    cmis.refundTicket();

    // 显示已售票
    cout << "显示所有已售出的票：" << endl;
    cmis.ShowSoldTickets();

    return 0;
}