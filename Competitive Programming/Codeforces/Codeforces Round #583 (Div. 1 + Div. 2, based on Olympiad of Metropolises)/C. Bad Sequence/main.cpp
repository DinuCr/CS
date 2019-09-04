#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int n,i,v[200100];
char x;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    int sum = 0;
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        if(x=='(')
           v[i]=1;
        else
            v[i]=-1;
        sum+=v[i];
    }
    if(sum!=0)
    {
        cout<<"No";
        return 0;
    }
    sum = 0;
    int ok = 1;
    for(i=1; i<=n; ++i)
    {
        sum+=v[i];
        if(sum<0)
        {
            if(ok)
                ok=0,sum=0;
            else
            {
                cout<<"No";
                return 0;
            }
        }

    }
    cout<<"Yes";
}
