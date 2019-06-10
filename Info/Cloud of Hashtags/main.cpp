#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int n,i,a1,b1,j,m;

string v[500010];
int lim[500010];

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    lim[n]=v[n].length();
    for(i=n-1; i>0; --i)
    {
        m = min(lim[i+1],(int)v[i].length());
        int ok=1;
        for(j=0; j<m; ++j)
            if(v[i][j]>v[i+1][j])
            {
                lim[i]=j;
                ok=0;
                break;
            }
            else
            if(v[i][j]<v[i+1][j])
            {
                lim[i]=v[i].length();
                ok=0;
                break;
            }
        if(ok)
            lim[i]=m;

    }
    for(i=1; i<=n; ++i)
    {
        for(j=0; j<lim[i]; ++j)
            cout<<v[i][j];
        cout<<'\n';
    }
}
