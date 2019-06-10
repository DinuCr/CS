#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

ifstream fin("granita.in");
ofstream fout("granita.out");

#define mp make_pair
#define pb push_back
#define s second
#define f first

vector < pair <int,int> > v;
int n,i,mx,a,b,nr;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>a>>b;
        v.pb(mp(a,b));
    }
    sort(v.begin(),v.end());

    mx=max(mx,v[0].s);

    for(i=1; i<n; ++i)
    {
        if(v[i].s<mx)
            nr++;
        mx=max(mx,v[i].s);
    }
    fout<<nr;
}
