#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back


    int i,j,n,m,a,c,b,d;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);


    cin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        if(x%2==0)
            ++a;
        else
            ++b;
    }
    for(j=1; j<=m; ++j)
    {
        int x;
        cin>>x;
        if(x%2==0)
            ++c;
        else
            ++d;
    }
    cout<<min(a,d)+min(b,c);
}
