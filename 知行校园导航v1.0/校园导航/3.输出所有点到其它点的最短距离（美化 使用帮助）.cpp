#include <iostream>
#include <windows.h>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <io.h>
#include <sstream>
#include <conio.h> 
#include<iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <io.h>
#include <stack>
#include <map>
using namespace std;

int road_AllRoad[101][101];
int bj_AllRoad[101];
map<int, string>dian_AllRoad;
stack<int>final_AllRoad;
stack<int>temp_AllRoad;
int minn_AllRoad, ans_AllRoad;

extern void find_AllRoad(int x, int end, int n)
{
	if (x == end)
	{ 
		if (minn_AllRoad < ans_AllRoad)
		{
			ans_AllRoad = minn_AllRoad;
			final_AllRoad = temp_AllRoad;
		}
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (road_AllRoad[x][i] > 0 && bj_AllRoad[i] == 0)//���ڵ�·��δ����� 
			{
				bj_AllRoad[i] = 1;
				temp_AllRoad.push(i);
				minn_AllRoad += road_AllRoad[x][i];

				find_AllRoad(i, end, n);
				minn_AllRoad -= road_AllRoad[x][i];
				temp_AllRoad.pop();
				bj_AllRoad[i] = 0;
			}
		}
	}
}

extern void AllRoad(string Map_address)
{
	MessageBoxA(NULL, "��Ϣ��ͬ��������ļ����������·.txt���У��ļ������ͬ��ͬһ��Ŀ¼���򿪸��ļ����ײ鿴���", "֪��У԰������ʹ�ð���", MB_OK);
	//cout << "��Ϣ��ͬ��������ļ����������·.txt���У��ļ������ͬ��ͬһ��Ŀ¼���򿪸��ļ����ײ鿴���" << endl;
	fstream allroad_out;
	allroad_out.open("./�������·.txt", ios::out);
	fstream allroad_in;
	allroad_in.open(Map_address, ios::in);

	//��ȡ��Ϣ
	int n, m;
	allroad_in >> n;
	string s;
	getline(allroad_in, s);
	for (int i = 1; i <= n; i++)
	{
		getline(allroad_in, s);
		dian_AllRoad[i] = s;
	}

	allroad_in >> m;
	for (int i = 1; i <= m; i++)
	{
		int x, y, l;
		allroad_in >> x >> y >> l;
		road_AllRoad[x][y] = l;
		road_AllRoad[y][x] = l;
	}
	allroad_in.close();

	
	cout << endl << "֪��У԰���������е㵽���������̾����·��" << endl;
	cout << "================================================" << endl<<endl;
	allroad_out << endl << "֪��У԰���������е㵽���������̾����·��" << endl;
	allroad_out << "================================================" << endl << endl;


	for (int begin = 1; begin <= n - 1; begin++)
	{
		for (int end = begin + 1; end <= n; end++)
		{
			allroad_out << "����: " << dian_AllRoad[begin] << " <===> " << dian_AllRoad[end] << endl;
			allroad_out << "================================================" << endl;
			cout << "����: " << dian_AllRoad[begin] << " <===> " << dian_AllRoad[end] << endl;
			cout << "================================================" << endl;
			minn_AllRoad = 0; ans_AllRoad = 999999999;
			memset(bj_AllRoad, 0, sizeof(bj_AllRoad));
			bj_AllRoad[begin] = 1;
			find_AllRoad(begin, end, n);
			stack<int>output;
			while (final_AllRoad.size() > 0)
			{
				output.push(final_AllRoad.top());
				final_AllRoad.pop();
			}
			int last = begin;
			allroad_out << "����·��: "<<dian_AllRoad[begin];
			cout << "����·��: " << dian_AllRoad[begin];
			while (output.size() > 0)
			{
				allroad_out << " <--" << road_AllRoad[last][output.top()] << "--> " << dian_AllRoad[output.top()];
				cout << " <--" << road_AllRoad[last][output.top()] << "--> " << dian_AllRoad[output.top()];
				last = output.top();
				output.pop();
			}
			allroad_out << endl;
			cout << endl;
			allroad_out << "------------------------------------------------" << endl;
			cout << "------------------------------------------------" << endl;
			allroad_out << "�ܳ��ȣ�" << ans_AllRoad << endl;
			allroad_out << endl;
			cout << "�ܳ��ȣ�" << ans_AllRoad << endl;
			cout << endl;
			allroad_out << endl;
			cout << endl;
		}
	}
	system("pause");
}