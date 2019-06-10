#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define pb push_back

string v[260];
int d[510][3];
int m;
vector <char> ans;
int n;
int curr[260];

bool op(char a,char b)
{
    if(a=='R')
    {
        if(b=='P')
            return 0;
        return 1;
    }
    else
    if(a=='P')
    {
        if(b=='R')
            return 1;
        return 0;
    }
    else
    if(a=='S')
    {
        if(b=='R')
            return 0;
        return 1;
    }
}

bool check(int k)
{
    for(int i=0; i<ans.size(); ++i)
    {
        if(ans[i]!=v[k][i%v[k].size()])
        {
            return op(ans[i],v[k][i%v[k].size()]);
        }
    }
    return 0;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    int cnt = 0;
    int t,i;
    cin>>t;
    while(t--)
    {
        ++cnt;
        cin>>n;
        for(i=1; i<=n; ++i)
            cin>>v[i];
        ans.clear();
        memset(d, 0, sizeof(d));
        m = 0;
        for(i=1; i<=n; ++i)
        {
            m = max(m,(int)v[i].size());
            curr[i]=1;
        }
        int skip = 0;
        int cont = 1;
        for(i=0; i<500 && cont; ++i)
        {
            for(int j=1; j<=n; ++j)
                if(curr[j]==1)
                {
                    if(v[j][i%v[j].size()]=='R')
                        d[i][0]=1;
                    if(v[j][i%v[j].size()]=='P')
                        d[i][1]=1;
                    if(v[j][i%v[j].size()]=='S')
                        d[i][2]=1;
                }
            if(d[i][0]+d[i][1]+d[i][2]==3)
            {
                cout<<"Case #"<<cnt<<": IMPOSSIBLE\n";
                skip=1;
                break;
            }
            else if(d[i][0] && d[i][1])
            {
                ans.pb('P');
            }
            else if(d[i][0] && d[i][2])
            {
                ans.pb('R');
            }
            else if(d[i][0])
            {
                ans.pb('P');
                break;
            }
            else if(d[i][1] && d[i][2])
            {
                ans.pb('S');
            }
            else if(d[i][1])
            {
                ans.pb('S');
                break;
            }
            else
            {
                ans.pb('R');
                break;
            }
            cont = 0;
            for(int j=1; j<=n; ++j)
                if(curr[j])
                {
                    if(ans[i]!=v[j][i%v[j].size()] && op(ans[i],v[j][i%v[j].size()]))
                        curr[j]=0;
                    else
                        cont=1;
                }
        }
        if(skip)
            continue;
        bool ok = 0;
        for(i=1; i<=n; ++i)
            ok |= check(i);
        if(!ok)
            cout<<"Case #"<<cnt<<": IMPOSSIBLE\n";
        else
        {
            cout<<"Case #"<<cnt<<": ";
            for(auto it:ans)
                cout<<it;
            cout<<'\n';
        }
    }
}
