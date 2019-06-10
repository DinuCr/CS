#include <iostream>
#include <algorithm>

using namespace std;

int v[100100],i,nr,a,b,c,n;

int main()
{
    cin>>n;
    v[0]=-1;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    sort(v+1,v+n+1);
    for(i=1; i<=n; ++i)
        if(v[i]!=v[i-1])
        {
            ++nr;
            if(nr==1)
                a=v[i];
            else
            if(nr==2)
                b=v[i];
            else
            if(nr==3)
                c=v[i];
        }
    if(nr<=2)
        cout<<"YES";
    else
    if(nr==3)
    {
        if(b-a==c-b)
            cout<<"YES";
        else
        cout<<"NO";
    }
    else
    cout<<"NO";
}
