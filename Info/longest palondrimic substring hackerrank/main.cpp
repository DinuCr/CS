#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

int n,i,r,l,rf,lf,c,d[2000100],ok,mx;
char v[2000100],s[1000100];

int main()
{
    //freopen("lps.in","r",stdin);

    cin.getline(s,1000100);
    n=strlen(s);

    v[0]='@';
    for(i=1; i<=n; ++i)
    {
       v[i*2]='@';
       v[i*2-1]=s[i-1];
    }

    n=2*n+1;

    d[0]=1;
    ok=1;
    int nr=0;

    //freopen("lps.out","w",stdout);

    for(i=1; i<=n && ok; ++i)
    {
        if(i<=c+d[c]/2 &&)
            d[i]=d[2*c-i];

        if(d[i]==0)
            d[i]=1;

        r=i+d[i]/2;
        l=i-d[i]/2;

        while(r<n && l>0 && v[r+1]==v[l-1])
            {
                d[i]+=2;
                ++r;
                --l;
                ++nr;
            }

        if(r>=n)
            ok=0;

        if(d[i]>mx)
        {
            mx=d[i];
            rf=r;
            lf=l;
        }

        if(i+d[i]/2>c+d[c]/2)
        {
            c=i;
        }
    }
    for(i=0; i<=n; ++i)
        cout<<s[i]<<' ';
    cout<<'\n';
    for(i=0; i<=n; ++i)
        cout<<d[i]<<' ';
    cout<<'\n';
    for(i=lf; i<=rf; ++i)
        if(v[i]!='@')
            cout<<v[i];
}
