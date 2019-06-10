#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

string s;
int d[100010][26];
int dp[255][255][255];
vector <char> sa,sb,sc;
int a,b,c;

void update(int p)
{
    int i,j,k;
    if(p==3)
        for(i=0; i<=a; ++i)
            for(j=0; j<=b; ++j)
            {
                k=c;
                dp[i][j][k]=1e9;
                if(i>0 && dp[i-1][j][k]!=1e9 && d[dp[i-1][j][k]][sa[i-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i-1][j][k]][sa[i-1]-'a']+1);

                if(j>0 && dp[i][j-1][k]!=1e9 && d[dp[i][j-1][k]][sb[j-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i][j-1][k]][sb[j-1]-'a']+1);

                if(k>0 && dp[i][j][k-1]!=1e9 && d[dp[i][j][k-1]][sc[k-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i][j][k-1]][sc[k-1]-'a']+1);
                }
    if(p==2)
        for(i=0; i<=a; ++i)
            for(k=0; k<=c; ++k)
            {
                j=b;
                dp[i][j][k]=1e9;
                if(i>0 && dp[i-1][j][k]!=1e9 && d[dp[i-1][j][k]][sa[i-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i-1][j][k]][sa[i-1]-'a']+1);

                if(j>0 && dp[i][j-1][k]!=1e9 && d[dp[i][j-1][k]][sb[j-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i][j-1][k]][sb[j-1]-'a']+1);

                if(k>0 && dp[i][j][k-1]!=1e9 && d[dp[i][j][k-1]][sc[k-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i][j][k-1]][sc[k-1]-'a']+1);
                }
    if(p==1)
        for(k=0; k<=c; ++k)
            for(j=0; j<=b; ++j)
            {
                i=a;
                dp[i][j][k]=1e9;
                if(i>0 && dp[i-1][j][k]!=1e9 && d[dp[i-1][j][k]][sa[i-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i-1][j][k]][sa[i-1]-'a']+1);

                if(j>0 && dp[i][j-1][k]!=1e9 && d[dp[i][j-1][k]][sb[j-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i][j-1][k]][sb[j-1]-'a']+1);

                if(k>0 && dp[i][j][k-1]!=1e9 && d[dp[i][j][k-1]][sc[k-1]-'a']!=-1)
                    dp[i][j][k]=min(dp[i][j][k], d[dp[i][j][k-1]][sc[k-1]-'a']+1);
                }


}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,q,i,j;

    cin>>n>>q;
    cin>>s;
    for(i=0; i<26; ++i)
        d[n][i]=-1;
    for(i=n-1; i>=0; --i)
    {
        for(j=0; j<26; ++j)
            d[i][j]=d[i+1][j];
        d[i][s[i]-'a']=i;
    }

    while(q--)
    {
        char ch,x;
        int k;

        cin>>ch>>k;
        if(ch=='-')
        {
            if(k==1)
                --a,sa.pop_back();
            if(k==2)
                --b,sb.pop_back();
            if(k==3)
                --c,sc.pop_back();
            if(dp[a][b][c]!=1e9)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            cin>>x;
            if(k==1)
                ++a,sa.pb(x);
            if(k==2)
                ++b,sb.pb(x);
            if(k==3)
                ++c,sc.pb(x);
            update(k);
            if(dp[a][b][c]!=1e9)
                cout<<"YES\n";
            else
                cout<<"NO\n";

        }
    }

}
