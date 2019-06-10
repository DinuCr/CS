#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("itree.in");
ofstream fout("itree.out");

vector <int> v[100100];
int a,b,i,ok,j;

int main()
{
    int t,n;
    fin>>t;
    while(t--)
    {
        fin>>n;
        ok=1;
        for(i=1; i<n; ++i)
        {
            fin>>a>>b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for(i=1; i<=n; ++i)
        {
            int nr=0;
            for(j=0; j<v[i].size(); ++j)
                if(v[v[i][j]].size()>1)
                    ++nr;
            if(nr>2 || v[i].size()==0)
                ok=0;
        }
        for(i=1; i<=n; ++i)
            v[i].clear();
        if(ok || n==1)
            fout<<"YES\n";
        else
            fout<<"NO\n";
    }
}
