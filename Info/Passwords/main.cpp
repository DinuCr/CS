#include <iostream>
#include <cstring>
using namespace std;

char s[1000];
int n,t,i,k,v[1000],ans;

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        cin>>s;
        v[strlen(s)]++;
    }
    cin>>s;
    ans=strlen(s);
    for(i=1; i<ans; ++i)
        t+=v[i];
    cout<<1+t+t/k*5<<' ';
    t+=v[ans];
    cout<<t+(t-1)/k*5;
}
