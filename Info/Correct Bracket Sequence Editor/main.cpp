#include <iostream>

using namespace std;

#define zeros(x) x&-x

char v[500100],o;
int c[500100],n,m,p,i,st[500100],k,s,d,sf,df;
int u[500100],a[500100];

int main()
{
    cin>>n>>m>>p;
    for(i=1; i<=n; ++i)
        cin>>v[i];

    for(i=1; i<=n; ++i)
    {
        if(v[i]=='(')
        {
            st[++k]=i;
        }
        else
        {
            c[i]=st[k];
            c[st[k]]=i;
            --k;
        }
    }
    for(i=1; i<=n; ++i)
    {
        a[i]=i-1;
        u[i]=i+1;
    }
    u[n]=n;
    a[1]=1;
    sf=1;
    df=n;
    for(i=1; i<=m; ++i)
    {
        cin>>o;
        switch(o)
        {
        case 'R':
            {
                p=u[p];
                break;
            }
        case 'L':
            {
                p=a[p];
                break;
            }
        case 'D':
            {
                if(v[p]==')')
                {
                    d=p;
                    s=c[p];
                }
                else
                {
                    s=p;
                    d=c[p];
                }

                u[a[s]]=u[d];
                if(u[d]==d)
                {
                    u[a[s]]=a[s];
                    df=a[s];
                }
                a[u[d]]=a[s];
                if(a[s]==s)
                {
                    a[u[d]]=u[d];
                    sf=u[d];
                }
                p=u[a[s]];

                break;
            }
        }
    }
    for(i=sf; i<=df; i=u[i])
    {
        cout<<v[i];
        if(i==df)
            break;
    }
}
