#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("economie.in");
ofstream fout("economie.out");

#define nmax (int) 5e4+10

int d[nmax];

int main()
{
    int n,i;
    fin>>n;
    vector <int> v;
    while(n--)
    {
        int x;
        fin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    d[0]=1;
    vector <int> ans;
    for(auto it:v)
    {
        if(d[it])
            continue;
        ans.push_back(it);
        for(i=0; i<=50000; ++i)
            if(d[i] && i+it<=50000)
                d[i+it]=1;
    }
    fout<<ans.size()<<'\n';
    for(auto it:ans)
        fout<<it<<'\n';
}
