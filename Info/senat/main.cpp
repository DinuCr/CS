#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("senat.in");
ofstream fout("senat.out");

#define nmax 110

vector <int> v[nmax];
char s[10010];
int viz[nmax];
int l[nmax];
int r[nmax];
int n,m,q,i;

bool pairup(int x)
{
    if(viz[x])
        return 0;
    viz[x]=1;
    for(auto it:v[x])
        if(!r[it])
        {
            l[x]=it;
            r[it]=x;
            return 1;
        }
    for(auto it:v[x])
        if(pairup(r[it]))
        {
            l[x]=it;
            r[it]=x;
            return 1;
        }
    return 0;
}

int main()
{
    fin>>m>>n;
    int x,y;

    fin.getline(s,10000);
    for(i=1; i<=n; ++i)
    {
        fin.getline(s,10000);
        int sz = strlen(s);
        for(int j=0; j<sz; ++j)
            if(s[j]<='9' && s[j]>='0')
            {
                int nr=0;
                while(s[j]<='9' && s[j]>='0')
                    nr=nr*10+s[j++]-'0';
                v[i].push_back(nr);
            }
    }

    int ok=1;
    while(ok)
    {
        ok=0;
        memset(viz, 0, sizeof(viz));
        for(i=1; i<=n; ++i)
            if(!l[i])
                ok|=pairup(i);
    }
    for(i=1; i<=n; ++i)
        if(!l[i])
        {
            fout<<'0';
            return 0;
        }
    for(i=1; i<=n; ++i)
        fout<<l[i]<<'\n';
}
