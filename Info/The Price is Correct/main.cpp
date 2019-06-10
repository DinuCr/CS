#include <iostream>
#include <fstream>
using namespace std;
//ifstream f("in.in");
//ofstream g("out.out");
long long i,p,k,n,t,nr,v[100000],x;
long long caut(long long ls,long long ld)
{
    long long m=(ls+ld)/2;
    if(ls<=ld)
    {
        long long x=v[m]-v[i-1];
        if(x>k)
            return caut(ls,ld-1);
        else
        if(x<k)
            return caut(ls+1,ld);
        else
            return m;
    }
    else
    return m;
}
int main()
{
    cin>>t;
    for(x=1;x<=t;x++)
    {
        cin>>n>>k;
        for(i=1;i<=n;i++)
        {
            cin>>v[i];
            v[i]+=v[i-1];
        }
        for(i=1;i<=n;i++)
        {
            p=caut(i,n);
            nr+=p-i+1;
        }
        cout<<"Case #"<<x<<": "<<nr<<'\n';
        nr=0;
    }
}
