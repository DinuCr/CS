#include <iostream>
#include <fstream>
#include <algorithm>
#include <set>
#include <iomanip>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

#define mp make_pair
#define f first
#define s second

const long double pi = (long double)3.141592653589793;
pair<long double,long double> v[1010];

int main()
{
    int t,n,k,i;
    fin>>t;
    int cnt = 0;
    while(t--)
    {
        ++cnt;
        fin>>n>>k;
        multiset <long double> q;
        for(i=1; i<=n; ++i)
        {
            fin>>v[i].f>>v[i].s;
            q.insert((long double)-v[i].s*v[i].f*pi*2);
        }
        sort(v+1,v+n+1);
        long double ans = 0;
        long double curr = 0;
        for(i=n; i>=k; --i)
        {
            curr = (long double)pi * v[i].f * v[i].f + pi*v[i].f*v[i].s*2;
            q.erase(q.lower_bound((long double)-v[i].s*v[i].f*pi*2));
            int x = k-1;
            for(std::multiset<long double>::iterator it=q.begin(); it!=q.end() && x; --x,++it)
                curr-=*it;
            ans = max(ans,curr);
        }
        fout<<setprecision(10)<<fixed<<"Case #"<<cnt<<": "<<ans<<'\n';
    }
}
