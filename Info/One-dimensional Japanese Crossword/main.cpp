#include <iostream>

using namespace std;

int n,nr,i,d[1000];
char v[1000];

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        if(v[i]=='B' && d[i-1]==0)
            ++nr;
        if(v[i]=='B')
            d[i]=d[i-1]+1;
        else
            d[i]=0;
    }
    cout<<nr<<'\n';
    for(i=1; i<=n; ++i)
        if(v[i]=='B' && v[i+1]!='B')
            cout<<d[i]<<' ';
}
