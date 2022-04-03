#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char c1[100];
    cin.get(c1,100,'\n');
    //cout<<c1<<endl;
    int a,b;
    a = strlen(c1);
    for(int i=0;i<a/2;i++)
    {
        if(c1[i]==c1[a-1-i]) b=0;
        else {b=1;break;}
    }
   if(b==0) cout<<"YES";
    else cout<<"NO";
    return 0;
}
