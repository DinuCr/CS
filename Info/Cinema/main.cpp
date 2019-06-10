#include <iostream>
#include <algorithm>

using namespace std;
int n,v[200100],u[200100],p[200100],a[200100],s[200100],mx1,mx2,i,m,x,N=1;

int bs(int s,int d,int c)
{
    if(s>=d)
        return s;
    else
    {
        int x=v[(s+d)/2];
        if(c==x)
            return (s+d)/2;
        if(c>x)
            return bs((s+d)/2+1,d,c);
        return bs(s,(s+d)/2-1,c);
    }
}


int numar(int x)
{
    int poz=bs(1,n,x);
    if(v[poz]==x)
        return u[poz]-p[poz]+1;
    else
        return 0;
}

int main()
{
    mx1=mx2=0;
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];

    sort(v+1,v+n+1);

    cin>>m;
    for(i=1; i<=m; ++i)
        cin>>a[i];
    for(i=1; i<=m; ++i)
        cin>>s[i];

    for(i=1; i<=n; ++i)
    {
        if(v[i]!=v[i-1])
            p[i]=i;
        else
            p[i]=p[i-1];
    }


    for(i=n; i>0; --i)
    {
        if(v[i]!=v[i+1])
            u[i]=i;
        else
            u[i]=u[i+1];
    }

    for(i=1; i<=m; ++i)
    {
        x=numar(a[i]);
        if(x>mx1)
        {
            N=i;
            mx1=x;
            mx2=numar(s[i]);
        }
        else
        if(x==mx1)
        {
            x=numar(s[i]);
            if(x>mx2)
            {
                N=i;
                mx2=x;
            }
        }
    }
    cout<<N;
}
