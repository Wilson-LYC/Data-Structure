#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <io.h>
#include <sstream>
#include <conio.h> 
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <direct.h>
#include <errno.h>
#include <vector>
#include<map>
#include<stack>

using namespace std;

void ChangeColor(int zt, int bj);
void ChangeXY(HANDLE hOut, int x, int y);
void CenterOut(string str, int line, int new_line);
void Change_Window(int width, int height);//��������� str:�ַ��� line:��������� new_line:1������� 0������
int ck_w_size();//���ش��ڿ��
int road[101][101];
int bj[101];
map<int, string>dian;
stack<int>final;
stack<int>temp;
int minn, ans;

void find(int x, int end, int n)
{
	if (x == end)
	{
		if (minn < ans)
		{
			ans = minn;
			final = temp;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (road[x][i] > 0 && bj[i] == 0)//���ڵ�·��δ����� 
			{
				bj[i] = 1;
				temp.push(i);
				minn += road[x][i];

				find(i, end, n);
				minn -= road[x][i];
				temp.pop();
				bj[i] = 0;
			}
		}
	}
}

extern void PtP(string Map_address,int begin,int end)
{
	//string Map_address;
    fstream txtin;
    txtin.open(Map_address, ios::in);
	int n, m;
	txtin >> n;
	string s;
	getline(txtin, s);
	for (int i = 1; i <= n; i++)
	{
		getline(txtin, s);
		dian[i] = s;
	}

	txtin >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, l;
		txtin >> x >> y >> l;
		road[x][y] = l;
		road[y][x] = l;
	}
	txtin.close();

	CenterOut("֪��У԰���������㵽�㡱����", 1, 0);
	CenterOut("===============================================", 2, 1);
	int oline = 2;
	oline++;
	CenterOut("[�ڵ�����]", oline, 0);
	cout << " ------- " << "[���]" << endl;
	for (auto i : dian)
	{
		//cout << setw(10) << i.first << " " << i.second << endl;
		oline++;
		//string text = to_string(i.first);
		CenterOut(i.second, oline, 0);
		cout << " ------- " << i.first << endl;
	}
	cout << endl;


	if (begin == -1 && end == -1)
	{
		oline++;
		CenterOut("===============================================", oline, 1);
		oline++;
		CenterOut("* ���⴦����0��������һ�� *", oline, 0);
		oline += 2;
	
		do
		{
			CenterOut("                                            ", oline, 0);
			CenterOut("����������ţ�", oline, 0);
			cin >> begin;
			if (begin == 0) return;
			if (dian.count(begin) == 0)
			{
				MessageBoxA(NULL, "�˵㲻���ڣ����������룡", "֪��У԰����������", MB_OK);
			}
		} while (dian.count(begin) == 0);

		oline++;
		do
		{
			CenterOut("                                            ", oline, 0);
			CenterOut("�������յ��ţ�", oline, 0);
			//cout << "�������յ㣺";;
			cin >> end;
			if (end == 0) return;
			if (dian.count(end) == 0)
			{
				MessageBoxA(NULL, "�˵㲻���ڣ����������룡", "֪��У԰����������", MB_OK);
			}
		} while (dian.count(end) == 0);
		
	}
	minn = 0; ans = 999999999;
	bj[begin] = 1;
	find(begin, end, n);

	stack<int>output;
	while (final.size() > 0)
	{
		output.push(final.top());
		final.pop();
	}
	int last = begin;
	cout << endl;
	system("cls");
	cout << endl<<"֪��У԰���������㵽�㡱����" << endl;
	cout << "================================================" << endl;
	cout << "����" << dian[begin] << "  ==> " << dian[end] << endl;
	cout << "------------------------------------------------" << endl;
	cout << "����·����"<<dian[begin];
	while (output.size() > 0)
	{
		cout << " --" << road[last][output.top()] << "--> " << dian[output.top()];
		last = output.top();
		output.pop();
	}
	cout << endl << "-----------------------------------------------" << endl;
	cout << "�ܳ��ȣ�" << ans << endl << endl;
	system("pause");
}
