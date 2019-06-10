#include <iostream>
using namespace std;
int n,v[5],nr,i,x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        v[x]++;
    }
    nr=v[4];
    if(v[3] && v[1])
    {
        nr+=min(v[3],v[1]);
        if(v[3]==max(v[1],v[3]))
            {
                v[3]-=v[1];
                v[1]=0;
            }
        else
            {
                v[1]-=v[3];
                v[3]=0;
            }
    }
    nr+=v[3];
    nr+=v[2]/2;
    v[2]%=2;
    nr+=v[1]/4;
    v[1]%=4;
    if(v[2] && v[1])
    {
        nr+=1;
        v[1]-=2;
        v[2]--;
    }
    if(v[1]>0)
        nr++;
    if(v[2])
        nr++;
    cout<<nr;
}
