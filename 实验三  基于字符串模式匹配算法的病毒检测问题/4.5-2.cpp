#include<iostream>
#include<string>

using namespace std;

int Index_BF(string, string, int); //ƥ���򷵻ؿ�ʼ�±꣬���򷵻�-1 
int Virus_detecion(string, string); //��Ⱦ�򷵻�1�����򷵻�0

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
{//����ģʽt������s�е�pos���ַ���ʼ��һ�γ��ֵ�λ���±ꡣ
//�������ڣ��򷵻�ֵΪ-1 
 //���У�t�ǿգ�1��pos��StrLength(s) 
	int i,j;
   	i = pos-1; //�±� 
	j = 0; //�±� 
   	while(i<s.length() && j<t.length()){ 
      	if(s[i]==t[j]){++i; ++j;}	//�����ȽϺ���ַ� 
      	else{i=i-j+1; j=0;}	//ָ��������¿�ʼƥ��
   }   
   if(j==t.length()) return i-t.length(); //ģʽ��ȫ�����꣬��ʾƥ�䣬���ؿ�ʼƥ��λ�õ��±� 
   else return -1;   
} 

int Virus_detecion(string t, string s)
{//�󲡶�DNA����״������DNA���Ƿ���֣����򷵻�����DNA�еڼ����ַ����֣����򷵻�0 
	int num = t.length();
	t += t; //ģʽ����������	
	string temp; 
	int res;
	for (int i=0; i<num; i++){
		temp.assign(t, i, num); 		
		//cout << temp << endl;
		res = Index_BF(s, temp, 1) ; //���� Index_BF ��Ȿ�ε�num���ַ��Ƿ���sƥ�� 
		if(res!=-1)  return 1; // ����ƥ�䣬˵����Ⱦ���� 
	}
	
	return 0; //���м�ⶼ��ƥ�䣬˵��û�и�Ⱦ���� 
}

/*�������ݼ������Ϣ��
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
