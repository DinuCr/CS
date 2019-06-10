#include <iostream>

using namespace std;
int ls,ld,m[400],f[400],i,s1,s2,mx,n;
char c;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>c>>ls>>ld;
        if(c=='M')
        {
            m[ls]+=1;
            m[ld+1]-=1;
        }
        else
        {
            f[ls]+=1;
            f[ld+1]-=1;
        }
    }
    for(i=0;i<=377;i++)
    {
        s1+=m[i];
        s2+=f[i];
        mx=max(mx,min(s1,s2)*2);
    }
    cout<<mx;
}
