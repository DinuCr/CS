#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("zeul.in");
ofstream fout("zeul.out");

#define nmax 100010
#define mp make_pair
#define f first
#define s second

int da[nmax];
int ia[nmax];
vector <int> fara;
vector <int> cu;
vector <pair<int,int> > ans;
int main()
{
    int i,n,m,a,b;
    fin>>n>>m;
    for(i=1; i<=m; ++i)
    {
        fin>>a>>b;
        ++da[a];
        ++ia[b];
    }
    for(i=1; i<=n; ++i)
    {
        if(da[i]>ia[i])
            fara.push_back(i);
        if(ia[i]>da[i])
            cu.push_back(i);
    }
    for(auto it:cu)
    {
        while(ia[it]>da[it])
        {
            ans.push_back(mp(it,fara.back()));
            da[it]++;
            ia[fara.back()]++;
            if(ia[fara.back()]==da[fara.back()])
                fara.pop_back();
        }
    }
    fout<<ans.size()<<'\n';
    for(auto it:ans)
        fout<<it.f<<' '<<it.s<<'\n';
}
