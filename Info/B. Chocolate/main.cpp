#include <iostream>

using namespace std;
long long p,n,i,v[200];
unsigned long long s;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    p=-1;s=1;
    for(i=1;i<=n;i++)
    {
        if(v[i]==1 && p>0)
        {
            s*=i-p;
            p=i;
        }
        else
            if(v[i]==1)
            p=i;
    }
    if(p==-1)
        s=0;
    cout<<s;
}
