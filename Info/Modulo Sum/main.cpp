#include <iostream>

using namespace std;
int n,m,i,j,x,v[1001][1001],k,ok=false;
int main()
{
    cin>>n>>m;
    if(n>=m)
        cout<<"YES";
    else
    {
        cin>>x;
        v[1][x%m]=1;
        if(v[1][0])
                ok=true;
        else
        for(i=2;i<=n;i++)
        {
            cin>>x;
            x%=m;
            v[i][x]=1;
            for(j=1;j<=m;j++)
                if(v[i-1][j])
                    {
                        v[i][(j+x)%m]=1;
                        v[i][j]=1;
                    }
            if(v[i][0])
            {
                ok=true;
                break;
            }
        }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
    }
}
