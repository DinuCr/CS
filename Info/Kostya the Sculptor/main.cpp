#include <iostream>
#include <algorithm>

using namespace std;

struct stone
{
    int a,b,c,nr;
};

stone v[100100];
int n,mx,ans1,ans2,ans;

int sfera(stone a)
{
    return min(a.a,min(a.b,a.c));
}

bool cmp1(const stone &a,const stone &b)
{
    if(a.a==b.a)
    {
        if(a.b==b.b)
            return a.c>b.c;
        return a.b<b.b;
    }
    return a.a<b.a;
}


void prel1()
{
    for(int i=0; i<n; ++i)
    {
        int j=i+1;
        if(v[i].a==v[j].a && v[i].b==v[j].b)
            {
                if(min(v[i].a,min(v[i].b,v[i].c+v[j].c))>mx)
                {
                    mx=min(v[i].a,min(v[i].b,v[i].c+v[j].c));
                    ans=2;
                    ans1=v[i].nr;
                    ans2=v[j].nr;
                }
            }
    }
}


int main()
{
    cin>>n;
    for(int i=0; i<n; ++i)
    {
        cin>>v[i].a>>v[i].b>>v[i].c;
        v[i].nr=i;
        int a = max(v[i].a,max(v[i].b,v[i].c));
        int c = min(v[i].a,min(v[i].b,v[i].c));
        int b = v[i].a+v[i].b+v[i].c-a-c;
        v[i].a=a;
        v[i].b=b;
        v[i].c=c;
        if(sfera(v[i])>mx)
        {
            ans=1;
            ans1=i;
            mx=sfera(v[i]);
        }
    }
    sort(v,v+n,cmp1);
    prel1();

    if(ans==1)
    {
        cout<<1<<'\n'<<ans1+1;
    }
    else
    cout<<2<<'\n'<<ans1+1<<' '<<ans2+1;
}
