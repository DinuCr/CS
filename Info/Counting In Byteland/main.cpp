#include <iostream>

using namespace std;

#define ll long long
#define zeros(x) ((x^(x-1))&x)
#define nmax 110

ll tree[nmax][nmax][nmax];
ll sum;
int n,q,x,y,z,val,X,Y,Z;

void add(int x,int y,int z,ll val)
{
    int i,j,k;
    for(i=x; i<=n; i+=zeros(i))
        for(j=y; j<=n; j+=zeros(j))
            for(k=z; k<=n; k+=zeros(k))
                tree[i][j][k]+=val;
}

ll compute(int x,int y,int z)
{
    int i,j,k;
    ll ans = 0;
    for(i=x; i>0; i-=zeros(i))
        for(j=y; j>0; j-=zeros(j))
            for(k=z; k>0; k-=zeros(k))
                ans+=tree[i][j][k];
    return ans;
}

ll ans(int x,int y,int z,int X,int Y,int Z)
{
    return sum - (compute(X,Y,Z) - compute(X,Y,z) - compute(X,y,Z) - compute(x,Y,Z) + compute(x,y,Z) + compute(x,Y,z) + compute(X,y,z) - compute(x,y,z));
}

int main()
{
    cin>>n>>q;
    ++n;
    while(q--)
    {
        int p;
        cin>>p;
        switch(p)
        {
        case 1:
            cin>>x>>y>>z>>val;
            sum+=val;
            add(x+1,y+1,z+1,val);
            break;
        case 2:
            cin>>x>>y>>z>>X>>Y>>Z;
            cout<<ans(x,y,z,X+1,Y+1,Z+1)<<'\n';
            break;
        }
    }
}
