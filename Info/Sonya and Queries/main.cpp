#include <iostream>
#include <map>

using namespace std;

int v[1000100];
long long p[21],i,n,x1,nr,p1,x,mx,ans,x2;


int main()
{
    p[0]=1;
    for(i=1; i<=19; ++i)
        p[i]=p[i-1]*2;

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        char c;
        cin>>c>>x;
        switch(c)
        {
        case '+':
            x1=0;p1=1;
            while(x)
            {
                x1=x1+x%2*p1;
                x/=10;
                p1*=10;
            }
            x2=0;
            p1=1;
            while(x1)
            {
                x2=x2+x1%10*p1;
                x1/=10;
                p1*=2;
            }
            v[x2]++;
            break;
        case '-':
            x1=0;p1=1;
            while(x)
            {
                x1=x1+x%2*p1;
                x/=10;
                p1*=10;
            }
            p1=1;
            x2=0;
            while(x1)
            {
                x2=x2+x1%10*p1;
                x1/=10;
                p1*=2;
            }
            v[x2]--;
            break;
        case '?':
            p1=1;
            x1=0;
            while(x)
            {
                x1=x1+x%10*p1;
                x/=10;
                p1*=2;
            }
            cout<<v[x1]<<'\n';
            break;
        }
    }
}
