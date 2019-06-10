#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

ll p2[65];
ll v[65];
ll state[(int)(1LL<<24)+10];
int d[(int)(1LL<<24)+10];
int m;

int most_imp(int n)
{
    int num = 0;
    if (!n) return -1;
    if (0xFFFF0000 & n) {
        n = (0xFFFF0000 & n)>>16;
        num += 16;
    }
    if (0xFF00 & n) {
        n = (0xFF00 & n) >> 8;
        num += 8;
    }
    if (0xF0 & n) {
        n = (0xF0 & n) >> 4;
        num += 4;
    }
    if (12 & n) {
        n = (12 & n) >> 2;
        num += 2;
    }
    if (2 & n) {
        n = (2 & n) >> 1;
        num += 1;
    }
    return num;
}

inline int min_lex(int &a,int &b)
{
    for(int i=0; i<=m ;++i)
    {
        if((a&p2[i])<(b&p2[i]))
            return b;
        if((a&p2[i])>(b&p2[i]))
            return a;
    }
    return a;
}


int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    p2[0]=1;
    for(int i=1; i<63; ++i)
        p2[i]=p2[i-1]*2;

    int n,i;

    cin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        int x;
        ll curr = 0;
        cin>>x;
        while(x--)
        {
            int a;
            cin>>a;
            curr+=p2[a-1];
        }
        v[i]=curr;
    }
    int lim = p2[m];
    int ans = 0;
    int mn = 100;
    for(i=1; i<lim; ++i)
    {
        int x = most_imp(i);
        state[i]=(long long)state[i-p2[x]]^v[x+1];
        d[i]=d[i-p2[x]]+1;
        if(state[i]==p2[n]-1LL)
        {
            if(d[i]<mn)
                mn=d[i],ans=i;
            else
            if(d[i]==mn)
            {
                ans = min_lex(i,ans);
            }
        }
    }
    cout<<mn<<'\n';
    for(i=0; i<=m+1; ++i)
        if(ans&p2[i])
            cout<<i+1<<' ';
}
