#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("transport.in");
ofstream fout("transport.out");

#define nmax 16100

int v[nmax];
int k,n,mn,i;

bool verif(int x)
{
    int s,nr=0;
    for(int i=1; i<=n; ++i)
    {
        int j;
        s=0;
        for(j=i; s+v[j]<=x && j<=n; ++j)
            s+=v[j];
        ++nr;
        if(v[j]>x)
            return 0;
        i=j-1;
    }
    if(nr<=k)
        return 1;
    return 0;
}

void bs(int s,int d)
{
    if(s>d)
        return ;
    int mid=(s+d)/2;
    if(verif(mid))
    {
        mn=mid;
        bs(s,mid-1);
    }
    else
        bs(mid+1,d);
}

int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    bs(0,nmax*nmax);
    fout<<mn;
}
