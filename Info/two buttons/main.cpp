#include <iostream>
using namespace std;
int n,m,v[100000],i,w[100000];
int main()
{
    cin>>n>>m;
    v[1]=n;w[1]=0;
    if(n==m)
        cout<<"0";
    else
    {
    n=1;
    for(i=1;i<=n;i++)
    {
        if(v[i]>1)
        {
            n++;
            v[n]=v[i]-1;
            w[n]=w[i]+1;
            if(v[n]==m)
            {
                cout<<w[n];
                break;
            }
        }
        if(v[i]<m)
        {
            n++;
            v[n]=2*v[i];
            w[n]=w[i]+1;
            if(v[n]==m)
            {
                cout<<w[n];
                break;
            }
        }

    }
    }
    return 0;
}
