#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("input.in");
ofstream fout("output.out");

#define mp make_pair
#define f first
#define s second

pair<int,int> v[200];
pair<int,int> w[200];
int n,m;

int main()
{
    int cnt = 0;
    int t,i;
    fin>>t;
    while(t--)
    {
        ++cnt;
        fout<<"Case #"<<cnt<<": ";
        fin>>n>>m;
        int sum1 = 0;
        int sum2 = 0;
        for(i=1; i<=n; ++i)
        {
            fin>>v[i].f>>v[i].s;
            sum1+=v[i].s-v[i].f;
        }
        for(i=1; i<=m; ++i)
        {
            fin>>w[i].f>>w[i].s;
            sum2+=w[i].s-w[i].f;
        }
        sort(v+1,v+n+1);
        sort(w+1,w+n+1);
        vector <int> curr;
        for(i=1; i<n; ++i)
            curr.push_back(v[i+1].f-v[i].s);
        if(n>1)
            curr.push_back(1440-v[n].s+v[1].f);
        sort(curr.begin(),curr.end());
        int ans = n * 2;
        for(auto it:curr)
            if(sum1+it<720)
                sum1+=it,ans-=2;
        int rez = ans;
        ans = m*2;
        curr.clear();
        for(i=1; i<m; ++i)
            curr.push_back(w[i+1].f-w[i].s);
        if(m>1)
            curr.push_back(1440-w[m].s+w[1].f);
        sort(curr.begin(),curr.end());
        for(auto it:curr)
            if(sum2+it<720)
                sum2+=it,ans-=2;
        rez = max(rez,ans);
        fout<<rez<<'\n';
    }
}
