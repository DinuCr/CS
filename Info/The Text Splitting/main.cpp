#include <iostream>
#include <cstring>
using namespace std;
int p,q,v[105],i,j,c[105],n,ok,nr;
char s[102];
int main()
{
    cin>>n>>p>>q;
    for(i=0;i<n;i++)
        cin>>s[i];
    v[0]=1;
    ok=1;
    for(i=1;min(i*p,i*q)<=n && ok;i++)
    for(j=0;j<=100 && ok;j++)
    {
        if(v[j]!=0)
        {
            v[j+p]=p;
            v[j+q]=q;
            if(j+p==n || j+q==n)
            ok=0;
        }
    }
    if(v[n]==0)
        cout<<"-1";
    else
    {
        i=n;nr=0;
        while(i!=0)
            c[++nr]=v[i],i-=v[i];
        cout<<nr<<'\n';
        p=0;
        for(i=nr;i>0;i--)
        {
            for(j=p;j<p+c[i];j++)
                cout<<s[j];
            cout<<'\n';
            p=p+c[i];
        }
    }
}
