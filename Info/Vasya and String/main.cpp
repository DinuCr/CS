#include <iostream>

using namespace std;

char v[100100];
int n,k,i,mx,nr,l,r;

int main()
{
    cin>>n>>k;

    cin>>v;

    nr=0;
    l=0;
    for(r=0; r<n; ++r)
    {
        if(v[r]=='b')
            nr++;
        if(nr>k)
        {
            while(v[l]=='a')
                ++l;
            l++;
            nr--;
        }
        mx=max(mx,r-l+1);
    }



    nr=0;
    l=0;
    for(r=0; r<n; ++r)
    {
        if(v[r]=='a')
            nr++;
        if(nr>k)
        {
            while(v[l]=='b')
                ++l;
            l++;
            nr--;
        }
        mx=max(mx,r-l+1);
    }

    cout<<mx;
}
