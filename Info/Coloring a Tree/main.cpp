#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <int> v[(int)1e4+10];
int c[(int)1e4+10];

#define f first
#define s second
#define mp make_pair

int ans;

void bf()
{
    queue<pair<int,int> > q;
    q.push(mp(1,0));
    while(!q.empty())
    {
        int x = q.front().f;
        int curr = q.front().s;
        q.pop();
        if(curr!=c[x])
            ++ans,curr=c[x];
        for(auto it:v[x])
            q.push(mp(it,curr));
    }
}
int main()
{
    int n,i;
    cin.sync_with_stdio(false);
    cin>>n;
    for(i=2; i<=n; ++i)
    {
        int x;
        cin>>x;
        v[x].push_back(i);
    }
    for(i=1; i<=n; ++i)
        cin>>c[i];
    bf();
    cout<<ans;
}
