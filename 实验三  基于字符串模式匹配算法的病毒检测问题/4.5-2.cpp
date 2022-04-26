#include<iostream>
#include<string>

using namespace std;

int Index_BF(string, string, int); //匹配则返回开始下标，否则返回-1 
int Virus_detecion(string, string); //感染则返回1，否则返回0

int main()
{
	int num;
	string s,t;
	cin>>num; 
	for(int i=1;i<=num;i++)
	{
		cin >> t >> s;
	if(Virus_detecion(t, s)==1)	cout << "YES" << endl;
	else cout << "NO" << endl;
    }
	return 0;	
}

int Index_BF(string s, string t, int pos)
{//返回模式t在主串s中第pos个字符开始第一次出现的位置下标。
//若不存在，则返回值为-1 
 //其中，t非空，1≤pos≤StrLength(s) 
	int i,j;
   	i = pos-1; //下标 
	j = 0; //下标 
   	while(i<s.length() && j<t.length()){ 
      	if(s[i]==t[j]){++i; ++j;}	//继续比较后继字符 
      	else{i=i-j+1; j=0;}	//指针后退重新开始匹配
   }   
   if(j==t.length()) return i-t.length(); //模式串全部读完，表示匹配，返回开始匹配位置的下标 
   else return -1;   
} 

int Virus_detecion(string t, string s)
{//求病毒DNA（环状）在人DNA中是否出现，有则返回在人DNA中第几个字符出现，无则返回0 
	int num = t.length();
	t += t; //模式串生成两次	
	string temp; 
	int res;
	for (int i=0; i<num; i++){
		temp.assign(t, i, num); 		
		//cout << temp << endl;
		res = Index_BF(s, temp, 1) ; //调用 Index_BF 检测本次的num个字符是否与s匹配 
		if(res!=-1)  return 1; // 本次匹配，说明感染病毒 
	}
	
	return 0; //所有检测都不匹配，说明没有感染病毒 
}

/*测试数据及输出信息：
2
cced cdccdcce
bcd aabccdxdxbxa
--------
YES
NO
=============
1
baa bbaabbba
-----
YES

==========
11
baa bbaabbba 
baa aaabbbba
aabb abceaabb
aabb abaabcea
abcd cdabbbab
abcd cabbbbab
abcde bcdedbda
acc bdedbcda
cde cdcdcdec
cced cdccdcce
bcd aabccdxdxbxa
-------
YES
YES
YES
YES
YES
NO
NO
NO
YES
YES
NO
*/
