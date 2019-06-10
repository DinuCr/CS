#include <iostream>
using namespace std;
long long i,n,w[5],v[5];
inline long long abs(long long x)
{
    if(x<0)
        return -x;
    return x;
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i]>>w[i];
    if(n==1)
        cout<<-1;
    else
    if(n==2)
    {
        if(v[1]!=v[2] && w[1]!=w[2])
            cout<<abs(v[1]-v[2])*abs(w[1]-w[2]);
        else
            cout<<-1;
    }
    else
    if(n==3)
    {
        if(v[1]!=v[3] && w[1]!=w[3])
        cout<<abs(v[1]-v[3])*abs(w[1]-w[3]);
        else
        if(v[1]!=v[2] && w[1]!=w[2])
        cout<<abs(v[1]-v[2])*abs(w[1]-w[2]);
        else
        if(v[1]!=v[2] && w[1]!=w[3])
        cout<<abs(v[1]-v[2])*abs(w[1]-w[3]);
        else
        cout<<abs(v[1]-v[3])*abs(w[1]-w[2]);
    }
    else
    {
        if(v[1]!=v[4] && w[1]!=w[4])
        cout<<abs(v[1]-v[4])*abs(w[1]-w[4]);
        else
        if(v[1]!=v[3] && w[1]!=w[3])
        cout<<abs(v[1]-v[3])*abs(w[1]-w[3]);
        else
        cout<<abs(v[1]-v[2])*abs(w[1]-w[2]);
    }
}
