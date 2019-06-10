#include <iostream>
#include <cstring>
using namespace std;
int n,i,nr,v[300],j;
char s[300];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
        cin>>s[i];
    for(i=1;i<=n;i++)
    {
        switch(s[i])
        {
        case 'U':
            v[i]=v[i-1]+1000;
            break;
        case 'D':
            v[i]=v[i-1]-1000;
            break;
        case 'R':
            v[i]=v[i-1]+1;
            break;
        case 'L':
            v[i]=v[i-1]-1;
            break;
        }
        if(v[i]==0)
            nr++;
    }
    for(i=1;i<n;i++)
    for(j=i+2;j<=n;j++)
    if(v[i]-v[j]==0)
    nr++;
    cout<<nr;
}
