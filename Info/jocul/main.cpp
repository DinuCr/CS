#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("jocul.in");
ofstream fout("jocul.out");

int l[1100],v[101000];
int n,i,j,s,m;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>l[i];
        s+=l[i];
    }
    v[0]=1;
    m=s/2;
    for(i=1; i<=n; ++i)
    {
        for(j=m; j>=0; --j)
            if(v[j]==1)
                if(j+l[i]<=m)
                    v[j+l[i]]=1;
    }
    for(i=m; i>=0; --i)
        if(v[i]==1)
        {
            fout<<i<<' '<<s-i;
            return 0;
        }
}
