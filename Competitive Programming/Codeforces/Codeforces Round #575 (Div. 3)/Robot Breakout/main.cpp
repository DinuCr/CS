#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

#define nmax (int)(1e5+10)

int x,y,a,b,c,d,curra,currb,currc,currd;
int qq,n,i;

void intersect(int &a,int &b, int &c, int &d, int x, int y, int z, int t)
{
    a=max(a,x);
    c=min(c,z);
    b=min(b,y);
    d=max(d,t);
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>qq;

    int q,w,e,r;

    while(qq--)
    {
        cin>>n;
        q=-1e5;
        w=1e5;
        e=1e5;
        r=-1e5;
        int ok=1;
        for(i=1; i<=n; ++i)
        {
            cin>>x>>y>>a>>b>>c>>d;
            if(a+b+c+d==4)
            {
                curra=-1e5;
                currb=1e5;
                currc=1e5;
                currd=-1e5;
            }
            else if(a+b+c+d==3)
            {
                if(c==0)
                {
                    curra=-1e5;
                    currb=1e5;
                    currc=x;
                    currd=-1e5;
                }
                if(a==0)
                {
                    curra=x;
                    currb=1e5;
                    currc=1e5;
                    currd=-1e5;
                }
                if(b==0)
                {
                    curra=-1e5;
                    currb=y;
                    currc=1e5;
                    currd=-1e5;
                }
                if(d==0)
                {
                    curra=-1e5;
                    currb=1e5;
                    currc=1e5;
                    currd=y;
                }
            }
            else
            if(a+b+c+d==2)
            {
                if(a+b==0)
                {
                    curra=x;
                    currb=y;
                    currc=1e5;
                    currd=-1e5;
                }
                if(a+c==0)
                {
                    curra=x;
                    currb=1e5;
                    currc=x;
                    currd=-1e5;
                }
                if(a+d==0)
                {
                    curra=x;
                    currb=1e5;
                    currc=1e5;
                    currd=y;
                }
                if(b+c==0)
                {
                    curra=-1e5;
                    currb=y;
                    currc=x;
                    currd=-1e5;
                }
                if(b+d==0)
                {
                    curra=-1e5;
                    currb=y;
                    currc=1e5;
                    currd=y;
                }
                if(c+d==0)
                {
                    curra=-1e5;
                    currb=1e5;
                    currc=x;
                    currd=y;
                }
            }
            else
            if(a+b+c+d==1)
            {
                if(a==1)
                {
                    curra=-1e5;
                    currb=y;
                    currc=x;
                    currd=y;
                }
                if(b==1)
                {
                    curra=x;
                    currb=1e5;
                    currc=x;
                    currd=y;
                }
                if(c==1)
                {
                    curra=x;
                    currb=y;
                    currc=1e5;
                    currd=y;
                }
                if(d==1)
                {
                    curra=x;
                    currb=y;
                    currc=x;
                    currd=-1e5;
                }
            }
            else
            {
                curra=x;
                currb=y;
                currc=x;
                currd=y;
            }
            intersect(q,w,e,r,curra,currb,currc,currd);
            if(r>w || q>e)
                ok=0;
        }
        if(ok==0)
            cout<<"0\n";
        else
        {
            cout<<1<<' '<<q<<' '<<w<<'\n';
        }
    }
}
