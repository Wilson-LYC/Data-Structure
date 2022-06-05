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

extern void ChangeColor(int zt, int bj)//改变文字颜色 zt:字体颜色 bj:背景颜色
{
	WORD wColor = ((bj & 0x0F) << 4) + (zt & 0x0F);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), wColor);
}

extern void ChangeXY(HANDLE hOut, int x, int y)//改变光标坐标到x,y
{
	COORD pos;
	pos.X = x; //横坐标
	pos.Y = y; //纵坐标
	SetConsoleCursorPosition(hOut, pos);
}

extern void CenterOut(string str, int line,int new_line)//行中心输出 str:字符串 line:输出的行数 new_line:1输出后换行 0不换行
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	int dwSizeX = bInfo.dwSize.X, dwSizey = bInfo.dwSize.Y;//获取控制台屏幕缓冲区大小
	int len = str.length();//获取要输出的字符串的长度
	int x = dwSizeX / 2 - len / 2;
	ChangeXY(hOutput, x, line); //移动光标
	cout << str;
	if (new_line) cout << endl;
}
extern int ck_w_size()
{
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO bInfo;
	GetConsoleScreenBufferInfo(hOutput, &bInfo);
	int dwSizeX = bInfo.dwSize.X, dwSizey = bInfo.dwSize.Y;//获取控制台屏幕缓冲区大小
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
	system(basic_ch);//修改窗口大小
}




