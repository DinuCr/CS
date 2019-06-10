#include <fstream>
#include <vector>
#include <deque>
using namespace std;
ifstream f("sortaret.in");
ofstream g("sortaret.out");
vector <int> v[50010];
int w[50010];
vector <int> r;
int i,j,n,m,a,b;
int main()
{
    f>>n>>m;
    for(i=1; i<=m; i++)
    {
        f>>a>>b;
        v[a].push_back(b);
        w[b]++;
    }
    for(i=1; i<=n; i++)
        if(!w[i])
            r.push_back(i);
    for(i=0; i<r.size(); ++i)
    {
        for(j=0;j<v[r[i]].size();++j)
        {
            w[v[r[i]][j]]--;
            if(!w[v[r[i]][j]])
                r.push_back(v[r[i]][j]);
        }
    }
    for(i=0; i<r.size(); ++i)
        g<<r[i]<<' ';
}
