#include<iostream>
#include<windows.h>
#include<fstream>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include <direct.h>
#include <io.h>
using namespace std;
extern void FirtstUse()
{
	if (_access("D:/Campus navigation", 0) == -1)//�ж��Ƿ���ڸ�Ŀ¼ 
	{
		cout << "����ʹ�ã����������С���" << endl;
		Sleep(1000);
		int a = _mkdir("D:/Campus navigation");//������Ŀ¼ 
		/*if (flag == 0)
		{
			cout<<"make successfully"<<endl;
		}
		else
		{
			cout<<"make errorly"<<endl;
		} �ж��Ƿ�ɹ������ļ���*/
		
		fstream txtout;
		txtout.open("D:/Campus navigation/gdufs.map", ios::out);
		txtout << "15" << endl;
		txtout << "����" << endl;
		txtout << "�ֿ�����" << endl;
		txtout << "�����" << endl;
		txtout << "Gogo�����" << endl;
		txtout << "��һ����" << endl;
		txtout << "�ڶ�����" << endl;
		txtout << "���ﲿ" << endl;
		txtout << "��ѧ¥" << endl;
		txtout << "ͼ���" << endl;
		txtout << "�˽�¥" << endl;
		txtout << "�칫¥" << endl;
		txtout << "ʵ��¥" << endl;
		txtout << "ѧ����������" << endl;
		txtout << "�����" << endl;
		txtout << "������" << endl;
		txtout << "24" << endl;
		txtout << "1 2 210" << endl;
		txtout << "2 4 900" << endl;
		txtout << "2 3 220" << endl;
		txtout << "2 11 1000" << endl;
		txtout << "3 6 100" << endl;
		txtout << "3 5 60" << endl;
		txtout << "3 8 200" << endl;
		txtout << "5 7 200" << endl;
		txtout << "5 9 880" << endl;
		txtout << "5 8 400" << endl;
		txtout << "6 8 700" << endl;
		txtout << "8 9 400" << endl;
		txtout << "8 10 350" << endl;
		txtout << "8 12 200" << endl;
		txtout << "10 12 300" << endl;
		txtout << "10 11 80" << endl;
		txtout << "11 12 270" << endl;
		txtout << "12 13 150" << endl;
		txtout << "9 13 150" << endl;
		txtout << "9 14 80" << endl;
		txtout << "13 14 150" << endl;
		txtout << "9 15 400" << endl;
		txtout << "15 14 420" << endl;
		txtout << "15 13 500" << endl;
		txtout.close();
		fstream txtout1;
		txtout1.open("D:/Campus navigation/test1.map", ios::out);
		txtout1 << "7" << endl;
		txtout1 << "1" << endl;
		txtout1 << "2" << endl;
		txtout1 << "3" << endl;
		txtout1 << "4" << endl;
		txtout1 << "5" << endl;
		txtout1 << "6" << endl;
		txtout1 << "7" << endl;
		txtout1 << "9" << endl;
		txtout1 << "1 4 1" << endl;
		txtout1 << "1 3 3" << endl;
		txtout1 << "1 2 1" << endl;
		txtout1 << "2 5 10" << endl;
		txtout1 << "2 7 1" << endl;
		txtout1 << "3 4 2" << endl;
		txtout1 << "4 5 3" << endl;
		txtout1 << "3 6 1" << endl;
		txtout1 << "7 6 1" << endl;
		txtout1.close();
	}
}