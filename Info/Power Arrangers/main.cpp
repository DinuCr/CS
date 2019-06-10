#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define s second
#define pb push_back

char v[1000];
int d[1000];
char ans[1000];
int f,i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    cin>>t>>f;
    while(t--)
    {
        memset(v, 0, sizeof(v));
        memset(d, 0, sizeof(d));
        for(i=5; i<=595; i+=5)
        {
            cout<<i<<'\n'<<flush;
            cin>>v[i];
            d[v[i]-'A']++;
        }
        for(i=0; i<5; ++i)
            if(d[i]==23)
            {
                ans[4]=i+'A';
            }
        memset(d, 0, sizeof(d));
        for(i=5; i<=595; i+=5)
            if(v[i]==ans[4])
            {
                cout<<(i-1)<<'\n'<<flush;
                cin>>v[i-1];
                d[v[i-1]-'A']++;
            }
        for(i=0; i<5; ++i)
            if(d[i]==5)
            {
                ans[3]=i+'A';
            }
        memset(d, 0, sizeof(d));
        for(i=4; i<=595; i+=5)
            if(v[i]==ans[3] && v[i+1]==ans[4])
            {
                cout<<i-1<<'\n'<<flush;
                cin>>v[i-1];
                d[v[i-1]-'A']++;
            }
        for(i=0; i<5; ++i)
            if(d[i]==1)
            {
                ans[2]=i+'A';
            }
        for(i=3; i<=595; i+=5)
            if(v[i]==ans[2] && v[i+1]==ans[3] && v[i+2]==ans[4])
            {
                cout<<i-1   <<'\n'<<flush;
                cin>>v[i-1];
                ans[0]=v[i-1];
            }
        ans[1]='A'+'B'+'C'+'D'+'E'-(ans[0]+ans[2]+ans[3]+ans[4]);
        cout<<ans[0]<<ans[1]<<ans[2]<<ans[3]<<ans[4]<<'\n'<<flush;
        char c;
        cin>>c;
        if(c=='N')
            return 0;
    }
}
