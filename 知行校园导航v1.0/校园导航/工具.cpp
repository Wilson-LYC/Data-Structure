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
#include <direct.h>
#include <errno.h>

using namespace std;

extern void ChangeColor(int zt, int bj)//�ı�������ɫ zt:������ɫ bj:������ɫ
{
	WORD wColor = ((bj & 0x0F) << 4) + (zt & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

extern void ChangeXY(HANDLE hOut, int x, int y)//�ı������굽x,y
{
	COORD pos;
	pos.X = x; //������
	pos.Y = y; //������
	SetConsoleCursorPosition(hOut, pos);
}

extern void CenterOut(string str, int line,int new_line)//��������� str:�ַ��� line:��������� new_line:1������� 0������
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	int dwSizeX = bInfo.dwSize.X, dwSizey = bInfo.dwSize.Y;//��ȡ����̨��Ļ��������С
	int len = str.length();//��ȡҪ������ַ����ĳ���
	int x = dwSizeX / 2 - len / 2;
	ChangeXY(hOutput, x, line); //�ƶ����
	cout << str;
	if (new_line) cout << endl;
}
extern int ck_w_size()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	int dwSizeX = bInfo.dwSize.X, dwSizey = bInfo.dwSize.Y;//��ȡ����̨��Ļ��������С
	return dwSizeX;
}
extern void StrToChar(char p[10086], string pp)
{
	int i;
	for (i = 0; i < pp.length(); i++)
		p[i] = pp[i];
	p[i] = '\0';
}

extern void Change_Window(int width, int height)
{
	string width_str = to_string(width);
	string height_str = to_string(height);
	string basic_co = "mode con cols=" + width_str + " lines=" + height_str;
	char basic_ch[10086];
	StrToChar(basic_ch,basic_co);
	system(basic_ch);//�޸Ĵ��ڴ�С
}




