#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("search.in");
ofstream fout("search.out");

int d[103][28][5003];
char v[103][5003];
int l[103];
int n,m;
vector <int> curr[103];

int main()
{
    int i,j,ans,k;
    fin>>n>>m;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i]+1;
        l[i]=strlen(v[i]+1);
    }
    for(i=1; i<=n; ++i)
    {
        for(j=0; j<26; ++j)
        {
            ans = l[i]+1;
            d[i][j][l[i]+1]=l[i]+2;
            for(k=l[i]; k>0; --k)
            {
                if(v[i][k]=='a'+j)
                    ans = k;
                d[i][j][k]=ans+1;
            }
        }
    }
    for(i=1; i<=n; ++i)
        curr[i].push_back(1),l[i]++;
    char c;
    while(m--)
    {
        fin>>c;
        if(c!='-')
            for(i=1; i<=n; ++i)
            {
                if(curr[i].back()>l[i])
                    ++curr[i].back();
                else
                    curr[i].push_back(d[i][c-'a'][curr[i].back()]);
            }
        else
        {
            for(i=1; i<=n; ++i)
            {
                if(curr[i].back()>l[i]+1)
                    --curr[i].back();
                else
                    curr[i].pop_back();
            }
        }
        ans = 0;
        for(i=1; i<=n; ++i)
            if(curr[i].back()<=l[i])
                ++ans;
        fout<<ans<<'\n';
    }
}
