#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("sirpie.in");
ofstream fout("sirpie.out");

int v[25];
int ans[25];
int used[25],n,i,j;

bool pie(int a,int b)
{
    while(b!=0)
    {
        int x = a%b;
        a=b;
        b=x;
    }
    if(a==1)
        return 1;
    return 0;
}

void bkt(int k)
{
    if(k==n+1)
    {
        for(int i=1; i<=n; ++i)
            fout<<ans[i]<<' ';
        fout<<'\n';
    }
    else
    {
        for(int i=1; i<=n; ++i)
            if(!used[i] && (k==1 || pie(ans[k-1],v[i])))
            {
                used[i]=1;
                ans[k]=v[i];
                bkt(k+1);
                used[i]=0;
            }
    }
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=1; i<=n; ++i)
        for(j=i+1; j<=n; ++j)
            if(v[j]<v[i])
                swap(v[i],v[j]);
    bkt(1);
}
