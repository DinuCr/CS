#include <iostream>
#include <algorithm>

using namespace std;

int v[10],mx,i;

int main()
{
    cin>>v[1]>>v[2]>>v[3]>>v[4]>>v[5];
    sort(v+1,v+6);

    for(i=1; i<=5; )
    if(v[i]==v[i+1] && v[i+1]==v[i+2])
        mx=max(mx,v[i]*3),i+=3;
    else
        if(v[i]==v[i+1])
        mx=max(mx,v[i]*2),i+=2;
        else
            ++i;
    cout<<v[1]+v[2]+v[3]+v[4]+v[5]-mx;
}
