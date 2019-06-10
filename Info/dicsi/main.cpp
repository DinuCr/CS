#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("dicsi.in");
ofstream fout("dicsi.out");

int v[100100];
int n,i,ans,j;

int main()
{
    fin>>n;
    ans = 0;
    v[1]=0;
    for(i=1; i<=n; ++i)
    {
        for(j=i*2; j<=n; j+=i)
        {
            v[j]=max(v[j],v[i]+1);
            ans = max(ans,v[j]);
        }
    }
    fout<<ans+1<<'\n';
    for(i=1; i<=n; ++i)
        fout<<v[i]+1<<' ';
}
