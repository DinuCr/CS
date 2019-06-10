#include <iostream>

using namespace std;

#define nmax 500010

int n,v[nmax],i,j,mx,p,a,b;

int main()
{
    cin>>n;

    for(i=1; i<=n; i++)
        cin>>v[i];

    for(i=1; i<=n; i++)
    {
        while(v[i]==v[i+1] && i<n)
            i++;
        p=i;
        while(v[i]!=v[i+1] && i<n)
            i++;
        if(i-p>1)
        {
            if(v[p]==v[i])
                for(j=p+1; j<i; j++)
                    v[j]=v[p];
            else
            {
                for(j=p+1; j<p+(i-p+1)/2; j++)
                    v[j]=v[p];
                for(j=p+(i-p+1)/2; j<i; j++)
                    v[j]=v[i];
            }
            mx=max(mx,(i-p)/2);
        }
    }

    cout<<mx<<'\n';

    for(i=1; i<=n; i++)
        cout<<v[i]<<' ';
}
