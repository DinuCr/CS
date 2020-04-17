#include <bits/stdc++.h>
#define P 73
#define mod1 100007
#define mod2 100021
#define mod3 100043
using namespace std;
ifstream fin("0-caracatita.in");
ofstream fout("caracatita.out");
int n,hash1,hash2,nr,m,q,k2,hash3;
int prez[509],num[509];
pair <char,int> vec[109];
char a[502][5509],ar[5509];
vector <pair< pair<int,int> ,int> > v[mod1+1];
int main()
{
    fin.sync_with_stdio(false);
    fin.tie(0);
    fin>>n;
    for(int i=1; i<=n; i++)
    {
        fin>>a[i]+1;
        m=strlen(a[i]+1);
        int k=0;
        for(int j=1; j<=m; j+=(num[i]+1))
            a[i][++num[i]]=a[i][j];
        for(int j=1; j<=num[i]; j++)
        {
            hash1=hash2=hash3=0;
            for(int p=j; p<=num[i]; p++)
            {
                hash1 = (hash1 * P + a[i][p]) % mod1;
                hash2 = (hash2 * P + a[i][p]) % mod2;
                hash3 = (hash3 * P + a[i][p]) % mod3;
                v[hash1].push_back({{hash2,hash3},i});
            }
        }
    }
    fin>>q;
    while(q)
    {
        q--;
        fin>>ar+1;
        m=strlen(ar+1);
        ar[0]='0';
        hash1=hash2=hash3=nr=k2=0;
        for(int i=1; i<=m; i++)
        {
            if(ar[i]!=ar[i-1])
            {
                hash1 = (hash1 * P + ar[i]) % mod1;
                hash2 = (hash2 * P + ar[i]) % mod2;
                hash3 = (hash3 * P + ar[i]) % mod3;
                vec[++k2]= {ar[i],1};
            }
            else
                vec[k2].second++;
        }
        if(k2>100)
            nr=0;
        else
        {
            for(auto it:v[hash1])
                if(it.first.first==hash2&&it.first.second==hash3)
                {
                    if(prez[it.second]==q+1)
                        nr++;
                    else
                    {
                        int cop=k2,s=vec[cop].second;
                        for(int i=num[it.second]; i>=1&&cop>=1; i--)
                        {
                            if(a[it.second][i]==vec[cop].first)
                            {
                                if(i>=s)
                                    cop--,s=vec[cop].second;
                                else
                                    s-=i;
                            }
                        }
                        if(cop==0)
                        {
                            nr++;
                            prez[it.second]=q+1;
                        }
                    }
                }
        }
        fout<<nr<<'\n';
    }
    return 0;
}
