#include <iostream>
#include <cstring>

using namespace std;

char s[200100];
char b[200100];
char a[200100];
int n,m,v[200100],ans;

bool check(int k)
{
    for(int i=0; i<n; ++i)
        b[i]=s[i];
    for(int i=1; i<=k; ++i)
        b[v[i]-1]=0;
    int q=0;
    for(int i=0; i<n; ++i)
        if(b[i]==a[q])
            ++q;
    if(q>=m)
        return 1;
    return 0;
}

void bs()
{
    int p=1;
    for( ; p<n; p<<=1);
    for( ; p; p>>=1)
        if(ans+p<=n && check(ans+p))
            ans+=p;
}


int main()
{
    cin>>s;
    cin>>a;
    n = strlen(s);
    m = strlen(a);
    for(int i=1; i<=n; ++i)
        cin>>v[i];
    bs();
    cout<<ans;
}
