#include <iostream>
#include <algorithm>
using namespace std;
struct nod
{
    int t,p;
};
bool compare(nod a,nod b)
{
    return a.p<b.p;
}
int n,c,s1,s2,t,i;
nod v[100];
int main()
{
    cin>>n>>c;
    for(i=1; i<=n; i++)
        cin>>v[i].p;

    for(i=1; i<=n; i++)
        cin>>v[i].t;

    sort(v+1,v+n+1,compare);
    for(i=1; i<=n; i++)
    {
        t+=v[i].t;
        s1+=max(0,v[i].p-c*t);
    }
    t=0;
    for(i=n; i>0; i--)
    {
        t+=v[i].t;
        s2+=max(0,v[i].p-c*t);
    }
    if(s1>s2)
        cout<<"Limak";
    if(s2>s1)
        cout<<"Radewoosh";
    if(s1==s2)
        cout<<"Tie";
}
