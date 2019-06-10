#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair

vector <pair<int,int> >v;

int main()
{
    int n,i,p,a,b;
    cin>>n>>p;
    for(i=1; i<=n; ++i)
    {
        cin>>a>>b;
        v.push_back(mp(a,b));
    }
    int curr = 0;
        for(i=0; i<n; ++i)
            if(v[i].f<=curr)
                curr=max(curr,v[i].s);
    if(curr>=p)
        cout<<"YES";
    else
        cout<<"NO";
}
