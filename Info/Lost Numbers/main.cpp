#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[15],i,j,n=6;
int w[15],ans[15];

pair<int,int> guess(int x)
{
    for(i=1; i<=6; ++i)
        for(j=i+1; j<=6; ++j)
            if(v[i]*v[j]==x)
                return mp(v[i],v[j]);
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    v[1]=4;
    v[2]=8;
    v[3]=15;
    v[4]=16;
    v[5]=23;
    v[6]=42;

    cout<<"? 1 2\n";
    cout.flush();
    cin>>w[1];

    cout<<"? 2 3\n";
    cout.flush();
    cin>>w[2];

    cout<<"? 4 5\n";
    cout.flush();
    cin>>w[3];

    cout<<"? 5 6\n";
    cout.flush();
    cin>>w[4];

    pair<int,int> a,b;

    a = guess(w[1]);
    b = guess(w[2]);
    if(a.f==b.f)
    {
        ans[2]=a.f;
        ans[1]=a.s;
        ans[3]=b.s;
    }
    else
    if(a.s==b.s)
    {
        ans[2]=a.s;
        ans[1]=a.f;
        ans[3]=b.f;
    }
    else
    if(a.f==b.s)
    {
        ans[2]=a.f;
        ans[1]=a.s;
        ans[3]=b.f;
    }
    else
    if(a.s==b.f)
    {
        ans[2]=a.s;
        ans[1]=a.f;
        ans[3]=b.s;
    }

    a = guess(w[3]);
    b = guess(w[4]);
    if(a.f==b.f)
    {
        ans[5]=a.f;
        ans[4]=a.s;
        ans[6]=b.s;
    }
    else
    if(a.s==b.s)
    {
        ans[5]=a.s;
        ans[4]=a.f;
        ans[6]=b.f;
    }
    else
    if(a.f==b.s)
    {
        ans[5]=a.f;
        ans[4]=a.s;
        ans[6]=b.f;
    }
    else
    if(a.s==b.f)
    {
        ans[5]=a.s;
        ans[4]=a.f;
        ans[6]=b.s;
    }

    cout<<"! "<<ans[1]<<' '<<ans[2]<<' '<<ans[3]<<' '<<ans[4]<<' '<<ans[5]<<' '<<ans[6]<<'\n';
    cout.flush();


}
