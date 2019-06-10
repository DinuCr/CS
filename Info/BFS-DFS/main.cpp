#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int)(4e4+1e2)

int bf[nmax];
int df[nmax];
int i,n;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>bf[i];
    for(i=1; i<=n; ++i)
        cin>>df[i];
    if(bf[2]!=df[2])
    {
        cout<<-1;
        return 0;
    }
    cout<<2*(n-1)-1<<'\n';
    for(i=2; i<=n; ++i)
        cout<<"1 "<<bf[i]<<'\n';
    for(i=3; i<=n; ++i)
        cout<<df[i-1]<<' '<<df[i]<<'\n';
}
