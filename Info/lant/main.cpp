#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <map>

using namespace std;

#define ll long long

ifstream fin("lant.in");
ofstream fout("lant.out");

int n;
int dp[35][35];
vector <string> v;
int d[155][155];
ll ans[155];

int main()
{
    int k;
    fin>>k;
    string s;
    int n = 0;
    while(fin>>s)
    {
        string curr;
        for(int i=0; i<s.length(); ++i)
            if(s[i]<='z' && s[i]>='a')
                curr.push_back(s[i]);
            else
            if(curr.length()>0)
            {
                v.push_back(curr);
                ++n;
                curr.clear();
            }
        if(curr.length()>0)
            v.push_back(curr),++n;
    }
    for(int i=0; i<v.size(); ++i)
        for(int j=i+1; j<v.size(); ++j)
        {
            int curr = 0;
            memset(dp,0,sizeof(dp));
            for(int a=0; a<v[i].length(); ++a)
                for(int b=0; b<v[j].length(); ++b)
                    if(v[i][a]==v[j][b])
                        dp[a+1][b+1]=dp[a][b]+1;
                    else
                        dp[a+1][b+1]=max(dp[a][b+1],dp[a+1][b]);
            d[i][j]=v[i].length()+v[j].length()-(dp[v[i].length()][v[j].length()]<<1);
        }
    ll r = 0;
    ans[0]=1;
    for(int i=0; i<n; ++i)
    {
        int ok=0;
        for(int j=i+1; j<n; ++j)
            if(d[i][j]<=k)
                ans[j]+=ans[i],ok=1;
        if(!ok)
            r+=ans[i];
    }
    fout<<r;
}
