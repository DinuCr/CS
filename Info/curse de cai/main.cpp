#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("cai.in");
ofstream fout("cai.out");

int a[1010];
int b[1010];
int d[1010][1010];
int n,i,j,t,ans;

int cmp(int a,int b)
{
    if(a>b)
        return 1;
    if(a<b)
        return -1;
    return 0;
}

int main()
{
    fin>>t;
    while(t--)
    {
        fin>>n;
        for(i=1; i<=n; ++i)
            fin>>a[i];
        for(i=1; i<=n; ++i)
            fin>>b[i];
        sort(a+1,a+n+1);
        sort(b+1,b+n+1,std::greater<int>());
        ans=-1010;
        for(i=0; i<=n; ++i)
            for(j=0; i+j<=n; ++j)
            {
                if(i>0 && j>0)
                    d[i][j]=max(d[i-1][j]+cmp(a[i],b[i+j]),d[i][j-1]+cmp(a[n-j+1],b[i+j]));
                else
                if(i>0)
                    d[i][j]=d[i-1][j]+cmp(a[i],b[i+j]);
                else
                if(j>0)
                    d[i][j]=d[i][j-1]+cmp(a[n-j+1],b[j+i]);

                if(i+j==n)
                    ans=max(ans,d[i][j]);
            }
        fout<<ans*200<<'\n';
        for(i=0; i<=n; ++i)
        {
            for(j=0; j<=n; ++j)
            {
               d[i][j]=0;
            }
        }
    }
}
