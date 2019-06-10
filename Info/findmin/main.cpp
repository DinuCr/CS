#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("findmin.in");
ofstream fout("findmin.out");

int v[1001000];
int ans[1001000];
int fr[1001000];
int x,i,n,mn;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        fr[v[i]]=i;
    }
    mn=1;
    ans[fr[1]]=-1;

    for(i=2; i<=n; ++i)
    {
        if(fr[mn]<fr[i])
            ans[fr[i]]=fr[mn];
        else
            ans[fr[i]]=-1;

        if(fr[i]<fr[mn])
            mn=i;
    }
    for(i=1; i<=n; ++i)
        fout<<ans[i]<<' ';
}
