#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[501][510];
int d[501][510];
int ans;
int n,m;


void build_simple_ans()
{
    cout<<"TAK\n";
    for(int i=1; i<=n; ++i)
        cout<<"1 ";
}

void build_ans(int k,int cnt)
{
    int i,j;
    int mn = 0,mx=0;
    for(i=1; i<=n; ++i)
        if(d[cnt][i]==0)
            ++mn;
        else if(d[cnt][i]==m)
            ++mx;
    if(n==mn+mx)
    {
        if(mx%2==1)
        {
            build_simple_ans();
            return ;
        }
        else
        {
            ans=0;
            return ;
        }
    }
    else
    {
        cout<<"TAK\n";
        if(mx%2==1)
        {
            for(i=1; i<=n; ++i)
                for(j=1; j<=m; ++j)
                    if(d[cnt][i]==m || d[cnt][i]==0)
                    {
                        cout<<"1 ";
                        break;
                    }
                    else if((v[i][j]&k)==0)
                    {
                        cout<<j<<' ';
                        break;
                    }

        }
        else
        {
            int ok = 0;
            for(i=1; i<=n; ++i)
                for(j=1; j<=m; ++j)
                    if(d[cnt][i]==m || d[cnt][i]==0)
                    {
                        cout<<"1 ";
                        break;
                    }
                    else if(ok==0 && (v[i][j]&k))
                    {
                        cout<<j<<' ';
                        ok=1;
                        break;
                    }
                    else if(ok==1 && (v[i][j]&k)==0)
                    {
                        cout<<j<<' ';
                        break;
                    }
        }
    }
}


int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int i,j,k;
    cin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            cin>>v[i][j];
    int cnt = 1;
    for(k=1; k<1024; k<<=1)
    {
        for(i=1; i<=n; ++i)
            for(j=1; j<=m; ++j)
                if(v[i][j]&k)
                    d[cnt][i]++;
        ++cnt;
    }
    cnt = 1;
    ans = 0;
    for(k=1; k<1024; k<<=1)
    {
        ans = 0;
        for(i=1; i<=n; ++i)
            if(d[cnt][i]!=0 || d[cnt][i]!=m)
            {
                ans = 1;
                break;
            }
        if(ans)
            build_ans(k,cnt);
        else if(d[cnt][1]==m && n%2==1)
        {
            build_simple_ans();
            return 0;
        }
        if(ans==1)
            return 0;
        ++cnt;
    }
    cout<<"NIE";
}
