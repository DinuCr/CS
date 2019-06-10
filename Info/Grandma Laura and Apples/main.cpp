#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
struct sir
{
    char s[15];
};
long long n,p,i;
long long m,nr;
sir v[45];
int main()
{
    scanf("%d %d",&n,&p);
    for(i=1;i<=n;i++)
    {
        scanf("%s",&v[i].s);
    }
    for(i=n;i>0;i--)
    if(!strcmp(v[i].s,"half"))
    {
        nr*=2;
        m+=nr/2;
    }
    else
    {
        nr+=5;
        nr*=2;
        m+=nr/2;
    }
    m*=p;
    cout<<m/10;
    if(m%10!=0)
        cout<<"."<<m%10;
}
