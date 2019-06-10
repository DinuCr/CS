#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

ifstream fin("reactii.in");
ofstream fout("reactii.out");

#define nmax 15500
#define mp make_pair
#define f first
#define s second

int v[nmax];
int i,n,q;

void solve()
{
    stack <pair<int,int> > q;
    for(i=1; i<=n; ++i)
    {
        int low = v[i];
        int high = v[i];
        while(!q.empty() && (q.top().f - high == 1 || low - q.top().s == 1))
        {
            high = max(high,q.top().s);
            low = min(low,q.top().f);
            q.pop();
        }
        q.push(mp(low,high));
    }
    q.pop();
    if(q.empty())
        fout<<"1\n";
    else
        fout<<"0\n";
}

int main()
{
    fin>>n>>q;
    while(q--)
    {
        for(i=1; i<=n; ++i)
        {
            fin>>v[i];
        }
        solve();
    }
}
