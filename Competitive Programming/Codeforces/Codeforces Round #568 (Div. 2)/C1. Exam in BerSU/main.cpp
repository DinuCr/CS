#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back


int v[200050];
int w[101];
int j;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,m ;
    cin>>n>>m;
    for(int i=1; i<=n; ++i)
    {
        cin>>v[i];
    }
    int curr_sum = 0;
    for(int i=1; i<=n; ++i)
    {
        int sum = curr_sum;
        int ans = 0;
        if(curr_sum + v[i] <= m)
        {
            cout<<"0 ";
            curr_sum+=v[i];
            w[v[i]]++;
            continue;
        }
        for(j=100; j>0; --j)
            if(w[j])
            {
                if(sum - w[j]*j + v[i] > m)
                    sum-=w[j]*j, ans+=w[j];
                else
                {
                    ans += floor((sum+v[i]-m+j-1)/j);
                    break;
                }
            }
        cout<<ans<<' ';
        curr_sum+=v[i];
        w[v[i]]++;
    }

}
