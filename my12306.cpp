#define _CRT_SECURE_NO_WARNINGS

#include"my12306.h"

int main() {
    CMIS cmis;

    // ������Щ�����Ѿ�ͨ��������ʽ��ɣ�����ֱ���ļ�����������main����֮ǰ�Ĳ���
    // ��ӳ�����Ϣ
    cmis.addTrainsInfo(); // �û���Ҫ������ʾ���복����Ϣ�����ʹ�� EOF (�� Ctrl+D �� Ctrl+Z) ��������

    // ע���û�
    cout << "��ʼ�û�ע�������" << endl;
    cmis.registerUser(); // �˴��ͺ���������Ҫ�ֶ���������

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