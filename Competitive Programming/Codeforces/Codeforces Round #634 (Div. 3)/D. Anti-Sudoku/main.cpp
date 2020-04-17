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
	while(t--)
    {
        int n,m;
        n = m = 9;
        int v[11][11];
        char c;
        for(int i=1; i<=n; ++i)
            for(int j=1; j<=m; ++j)
            {
                char c;
                cin>>c;
                v[i][j]=c-'0';
            }
        int y = 1;
        for(int i=1; i<=9; ++i)
            {
                if(y==10)
                    y=2;
                if(y==11)
                    y=3;
                int x = i;
                v[x][y] = v[x][y]+1;
                if(v[x][y]==10)
                    v[x][y]=1;
                y+=3;
            }
        for(int i=1; i<=n; ++i)
        {
            for(int j=1; j<=m; ++j)
                cout<<v[i][j];
            cout<<'\n';
        }
    }

}
