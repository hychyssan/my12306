#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"

int main() {

    CMIS cmis;

    // ��ӳ�����Ϣ
    cmis.addTrainsInfo(); // �û���Ҫ������ʾ���복����Ϣ�����ʹ�� Ctrl+Z ��������

    // ע���û�
    cout << "��ʼ�û�ע�������" << endl;
    cmis.registerUser(); 

    // ��Ʊ
    cout << "��ʼ��Ʊ������" << endl;
    cmis.buyTicket();

    cmis.ShowSoldTickets();

    // ��Ʊ
    cout << "��ʼ��Ʊ������" << endl;
    cmis.refundTicket();

    // ��ʾ����Ʊ
    cout << "��ʾ�������۳���Ʊ��" << endl;
    cmis.ShowSoldTickets();

    return 0;
}