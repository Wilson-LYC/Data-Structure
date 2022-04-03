/*studentID£º20211003153*/
/*name£ºÀµÓÀ³¬*/
/*class£º¼ÆËã»ú2101*/
/*date£º2022-3-17*/
#include<iostream>
using namespace std;
struct stu
{
    int id;
    string name;
    double sco[3];
}peo[1000];
int main()
{
    int n;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&peo[i].id);
        cin>>peo[i].name;
        scanf("%lf %lf %lf",&peo[i].sco[0],&peo[i].sco[1],&peo[i].sco[2]);

    }
    int i;
    
    for(int i=1;i<=n;i++)
    {
        printf("%d ",peo[i].id);
        cout<<peo[i].name<<" ";
        printf("%.1lf %.1lf %.1lf\n",peo[i].sco[0],peo[i].sco[1],peo[i].sco[2]);
    }
}
