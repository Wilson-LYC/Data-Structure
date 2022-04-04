#include<iostream>
#include<map>
using namespace std;
map<int,int> num;
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        num[y]+=x;
    }
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        int x,y;
        cin>>x>>y;
        num[y]+=x;
    }
    int bj=0;   
    map<int,int>::reverse_iterator rit;
    for(rit = num.rbegin();rit != num.rend();rit++)//从后向前  
    {  
        if (rit->second!=0)
        {
            if (bj==1) cout<<" ";
            cout<<rit->second<<" "<<rit->first;  
             bj=1;
        }
        
    }  
    if (bj==0) cout<<"0 0";
}




