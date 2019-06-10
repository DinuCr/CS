#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("calatorie.in");
ofstream fout("calatorie.out");

const long long inf = 1000000000000;
long long d[60][600],v[60][2],mn,i,j,s,n,t;

int main()
{
    fin>>t;
    for(;t--;)
    {
        fin>>n;
        --n;
        s=0;
        for(i=1; i<=n; ++i)
        {
            fin>>v[i][0]>>v[i][1];
            s+=v[i][1];
        }
        for(i=0; i<=n; ++i)
            for(j=0; j<=s; ++j)
                d[i][j]=inf;
        d[0][0]=0;
        for(i=0; i<n; ++i)
            for(j=0; j<=s; ++j)
            if(d[i][j]!=inf)
            {
                d[i+1][j]=min(d[i+1][j],d[i][j]+v[i+1][0]);
                d[i+1][j+v[i+1][1]]=min(d[i+1][j+v[i+1][1]],d[i][j]);
            }
        mn=inf;
        for(i=0; i<=s; ++i)
            mn=min(mn,d[n][i]+i*i*i*i);
        fout<<"Consumul minim = "<<mn<<".\n";
    }
}
