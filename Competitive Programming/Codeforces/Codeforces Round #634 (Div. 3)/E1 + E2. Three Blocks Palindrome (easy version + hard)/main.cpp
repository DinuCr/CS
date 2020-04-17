#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

ifstream fin("");
ofstream fout("");


int sum[200100][202];

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
    {
        int n;
        vector <int> v;
        cin>>n;
        for(int i=1; i<=n; ++i)
        {
            int x;
            cin>>x;
            v.pb(x);
        }
        for(int i=0; i<n; ++i)
        {
            for(int j=1; j<=200; ++j)
                sum[i][j]=sum[i-1][j];

            sum[i][v[i]]++;
        }
        int ans = 1;
        for(int i=1; i<=200; ++i)
        {
            int a = 0;
            int b = n-1;
            int x = 0;
            while(a<b)
            {
                while(a<b && v[a]!=i)
                    ++a;
                if(a==b)
                    break;
                while(a<b && v[b]!=i)
                    --b;
                if(a==b)
                    break;
                ++x;
                int w[201];
                memset(w, 0, sizeof(w));

                for(int j=1; j<=200; ++j)
                    w[j]=sum[b-1][j] - sum[a][j];


                int mx = 0;
                for(int j=1; j<=200; ++j)
                    mx = max(mx, w[j]);
                ans = max(ans, x*2+mx);
                ++a;
                --b;
            }
        }
        cout<<ans<<'\n';
    }
}
