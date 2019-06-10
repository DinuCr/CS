#include <iostream>
using namespace std;
int v[100],n,i,x,m;
void heap()
{
    int p,c,i;
    for(i=2;i<=n;i++)
    {
        c=i;
        p=c/2;
        while(p>=1)
        {
            if(v[c]>v[p])
            {
                swap(v[c],v[p]);
                c=p;
                p=c/2;
            }
            else
            p=0;
        }
    }
}
void inserare(int &n,int x)
{
    int c,p,i;
    n++;
    v[n]=x;
    c=n;
    p=n/2;
    while(p>=1)
        {
            if(v[c]>v[p])
            {
                swap(v[c],v[p]);
                c=p;
                p=c/2;
            }
            else
            p=0;
        }
}
void heapsort(int a[])
{
    int c,p,i;
    for(i=n;i>1;i--)
    {
        swap(a[1],a[i]);
        p=1;
        c=2;
        while(c<i)
        {
            if(a[c+1]>a[c] && c+1<i)
            c++;
            if(a[c]>a[p])
            {
                swap(a[c],a[p]);
                p=c;
                c=2*p;
            }
            else
            c=i;
        }
    }
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        inserare(m,x);
    }

    heapsort(v);
    for(i=1;i<=n;i++)
    cout<<v[i]<<' ';
}
