#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

char v[200010];
int ans[200010];
int n,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    int last_d = 0;
    int last_i = 0;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        if(v[i]=='(')
        {
            if(last_d==0)
                ans[i]=1;
            else
                ans[i]=0;
            last_d = !last_d;
        }

        if(v[i]==')')
        {
            if(last_i==0)
                ans[i]=1;
            else
                ans[i]=0;
            last_i = !last_i;
        }
    }
    for(i=1; i<=n; ++i)
        cout<<ans[i];
}
