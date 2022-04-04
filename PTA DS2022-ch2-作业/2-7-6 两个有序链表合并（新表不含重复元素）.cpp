#include<iostream>
#include<map>
using namespace std;
map<long long,long long>ans;
int main()
{
    long long a;
    do
    {
        cin>>a;
        if (a!=-1) ans[a]++;
    }while(a!=-1);
    
    do
    {
        cin>>a;
        if (a!=-1) ans[a]++;
    }while(a!=-1);
    int bj=0;
    for (auto i:ans)
    {
        if (bj==1) cout<<" ";
        cout<<i.first;
        bj=1;
    }
    if (bj==0) cout<<"NULL";
}
