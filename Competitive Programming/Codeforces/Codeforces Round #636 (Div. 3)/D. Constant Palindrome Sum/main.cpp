#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

ifstream fin("");
ofstream fout("");

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);

	int t;
	cin>>t;
    int w[(int)2e5+10];
	while(t--)
    {
        int n,k;
        cin>>n>>k;
        for(int i=1; i<=n; ++i)
            cin>>w[i];
        int v[2*k+1];
        memset(v, 0, sizeof(v));
        for(int i=1; i<=n/2; ++i)
        {
            int a = w[i];
            int b = w[n-i+1];
            if(a>b)
                swap(a,b);
            v[2]+=2;
            v[a+1]-=2;

            v[a+1]+=1;
            v[a+b]-=1;

            v[a+b+1]+=1;
            v[b+k+1]-=1;

            v[b+k+1]+=2;
            v[k+k+1]-=2;
        }
        int curr = 0;
        int ans = 1e9;
        for(int i=2; i<=2*k; ++i)
        {
            curr+=v[i];
            ans = min(ans, curr);
        }
        cout<<ans<<'\n';

    }

}
