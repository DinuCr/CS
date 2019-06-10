#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

char v[100][100];
int n,i,j;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
    {
        cin>>v[i][j];
    }

    for(i=1; i<=n; ++i)
        for(j=1; j<=n; ++j)
        if(v[i][j]=='.')
        {
            if(v[i+1][j]=='.' && v[i+1][j-1]=='.' && v[i+1][j+1]=='.' && v[i+2][j]=='.')
                v[i][j]=v[i+1][j]=v[i+1][j-1]=v[i+1][j+1]=v[i+2][j]='#';
            else
            {
                cout<<"NO";
                return 0;
            }
        }
    cout<<"YES";
}
