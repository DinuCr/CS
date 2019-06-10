#include <iostream>

using namespace std;
int v[50],n,i;
void pl(int ls,int ld)
{
    if(ls!=ld)
    {
        for(i=(ls+ld+1)/2;i<=ld;i++)
            v[i]=v[ls+ld-i];
        pl((ls+ld)/2+1,ld);
    }
    else
        cout<<v[ls];
}
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>v[i];
    pl(1,n);
}
