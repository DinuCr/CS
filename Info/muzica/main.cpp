#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("muzica.in");
ofstream fout("muzica.out");

#define pb push_back
const int mod = 8011;

vector <int> h[8011];
int n,m,a,b,c,d,e,x,i,ans;

inline void add(int x)
{
    h[x%mod].pb(x);
}

bool exist(int x)
{
    int k = x%mod;
    for(int i=0; i<h[k].size(); ++i)
    if(h[k][i]==x)
    {
        swap(h[k][i],h[k][h[k].size()-1]);
        h[k].pop_back();
        return 1;
    }
    return 0;
}

int main()
{
    fin>>n>>m;
    fin>>a>>b>>c>>d>>e;

    for(i=1; i<=n; ++i)
    {
        fin>>x;
        add(x);
    }
    ans+=exist(a);
    ans+=exist(b);
    for(i=3; i<=m; ++i)
    {
        x = (1LL*b*c+1LL*d*a)%e;
        ans+=exist(x);
        a=b;
        b=x;
    }
    fout<<ans;
}
