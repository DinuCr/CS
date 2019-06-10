#include <iostream>
#include <utility>

using namespace std;

#define f first
#define s second

int n,m,i,j;
pair<int,int> a[1000];
int v[1000];

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=m; ++i)
        cin>>a[i].f>>a[i].s;
    int ans=0;
    for(i=1; i<=m; ++i)
    {
        int curr=0;
        for(j=a[i].f; j<=a[i].s; ++j)
            curr+=v[j];
        if(curr>0)
            ans+=curr;
    }
    cout<<ans;
}
