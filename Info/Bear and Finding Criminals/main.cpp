#include <iostream>

using namespace std;
int v[110],s,d,nr,a,n,i;
int main()
{
    cin>>n>>a;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    if(v[a])
        nr++;
    s=a-1;
    d=a+1;
    while(s>0 || d<=n)
    {
        if(s>0 && d<=n)
        {
            if(v[s]+v[d]==2)
                nr+=2;
            s--;
            d++;
        }
        else
        {
            if(s>0)
                {if(v[s])
                nr++;
                s--;}
            if(d<=n)
                {if(v[d])
                nr++;
            d++;}
        }
    }
    cout<<nr;
}
