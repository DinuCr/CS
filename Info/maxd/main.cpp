#include <fstream>
#include <climits>
#include <cmath>

using namespace std;
ifstream fin("maxd.in");
ofstream fout("maxd.out");
int v[44731],p[46500],i,stg,smax,smin,nrt,k,j,a,b,cop,s,nr,x;
int main()
{
    fin>>a>>b;
    p[1]=2;
    k=1;
    for(i=4;i<=44722;i+=2)
        v[i]=1;
    for(i=3;i<=44722;i+=2)
    {
        if(v[i]==0)
        {
            for(j=i+i;j<=44722;j+=i)
                v[j]=1;
            k++;
            p[k]=i;
        }
    }
    v[1]=1;
    for(i=a;i<=b;i++)
    {
        j=1;
        cop=i;
        s=1;
        x=sqrt(cop);
        while(cop>1&&p[j]<=x&&p[j])
        {
            nr=0;
            while(cop%p[j]==0)
            {
                nr++;
                cop/=p[j];
            }
            s*=(nr+1);
            j++;
        }
        if(cop>1)
            s*=2;
        if(s==smax)
            nrt++;
        if(s>smax)
        {
            nrt=1;
            smax=s;
            smin=i;
        }
    }
    fout<<smin<<" "<<smax<<" "<<nrt;
    return 0;
}
