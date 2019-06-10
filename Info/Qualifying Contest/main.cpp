#include <iostream>

using namespace std;
struct sir
{
    char s[100];
    int val;
    int ok;
};
int n,m,i,j;
sir v[3][10100];
int main()
{
    cin>>n>>m;
    sir a;
    int x;
    for(i=1;i<=n;++i)
    {
        cin>>a.s>>x>>a.val;
        if(v[2][x].val<a.val)
        {
            v[2][x]=a;
            v[2][x].ok=0;
            if(v[2][x].val>v[1][x].val)
                swap(v[1][x],v[2][x]);
        }
        else
        {
            if(v[2][x].val==a.val)
                v[2][x].ok=1;
        }
    }
    for(i=1;i<=m;i++)
    if(v[1][i].ok+v[2][i].ok==0)
    cout<<v[1][i].s<<' '<<v[2][i].s<<'\n';
    else
    cout<<"?\n";
}
