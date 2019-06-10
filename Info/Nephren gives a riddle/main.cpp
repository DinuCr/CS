#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e5+10
#define ll unsigned long long

string s0,si;

ll v[nmax],k;

void divide(ll k,ll n)
{
    if(n==0)
    {
        if(k<s0.length())
            cout<<s0[k];
        else
            cout<<'.';
    }
    else
    if(k<34)
    cout<<si[k];
    else
    if(34+v[n-1]<=k && k<34+v[n-1]+32)
    {
        k-=v[n-1];
        cout<<si[k];
    }
    else
    if(v[n]-2<=k && k<v[n])
    {
        if(k==v[n]-2)
            cout<<'"';
        else
            cout<<'?';
    }
    else
    if(k>=v[n])
        cout<<'.';
    else
    if(34<=k && k<34+v[n-1])
    {
        k-=34;
        divide(k,n-1);
    }
    else
    {
        k-=34+32+v[n-1];
        divide(k,n-1);
    }
}

int main()
{
    s0 = "What are you doing at the end of the world? Are you busy? Will you save us?";
    si =  "What are you doing while sending \"\"? Are you busy? Will you send \"\"?";
    int i,m;
    cin>>m;
    v[0]=s0.length();
        for(i=1; i<=1e5; ++i)
            if(v[i-1]<1e18)
                v[i]=v[i-1]*2+si.length();
            else
                v[i]=9e18;
    while(m--)
    {
        int n;
        cin>>n>>k;
        --k;
        divide(k,n);
    }
}
