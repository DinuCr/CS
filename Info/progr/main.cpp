#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("progr.in");
ofstream fout("progr.out");

const int mod = 8011;

vector <int> h[8011];
int n,t,i,j,ans;
int v[2010];

void add(int x)
{
    h[x%mod].push_back(x);
}

bool exist(int x)
{
    int k = x%mod;
    for(int i=0; i<h[k].size(); ++i)
        if(h[k][i]==x)
            return 1;
    return 0;
}

int main()
{
    fin>>t;
    while(t--)
    {
        ans=0;
        fin>>n;
        for(i=1; i<=n; ++i)
        {
            fin>>v[i];
            add(v[i]);
        }
        sort(v+1,v+n+1);
        for(i=1; i<n; ++i)
            for(j=i+1; j<=n; ++j)
                if(!exist(v[j]+(v[j]-v[i])))
                    ++ans;
        for(i=0; i<8011; ++i)
            while(h[i].size())
                h[i].pop_back();
        fout<<ans<<'\n';
    }
}
