#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;
ifstream f("cautbin.in");
ofstream g("cautbin.out");
int v[100010];
int n,m,y,i,p,x;
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>v[i];
    }
    f>>m;
    for(i=1;i<=m;i++)
    {
        f>>p>>y;
        switch(p)
        {
        case 0:
            x=upper_bound(v+1,v+n+1,y)-v-1;
            if(v[x]==y)
                g<<x<<'\n';
            else
                g<<"-1\n";
            break;
        case 1:
            x=upper_bound(v+1,v+n+1,y)-v-1;
            g<<x<<'\n';
            break;
        case 2:
            x=lower_bound(v+1,v+n+1,y)-v;
            g<<x<<'\n';
            break;
        }
    }
}
