#include <iostream>
#include <cstring>

using namespace std;

struct sir
{
    char s[505];
};

sir v[1010];
sir w[1010];
int n,m,i,j,cnt;

bool cmp(sir a,sir b)
{
    int n = strlen(a.s);
    if(n!=strlen(b.s))
        return 0;
    else
        for(int i=0; i<n; ++i)
            if(a.s[i]!=b.s[i])
                return 0;
    return 1;
}

int main()
{
    cin>>n>>m;
    for(i=1; i<=n; ++i)
        cin>>v[i].s;
    for(i=1; i<=m; ++i)
    {
        cin>>w[i].s;
        for(j=1; j<=n; ++j)
        {
            if(cmp(v[j],w[i])==1)
            {
                ++cnt;
                break;
            }
        }
    }
    n-=cnt;
    m-=cnt;
    if(cnt%2==0)
        ++m;
    if(n>=m)
        cout<<"YES";
    else
        cout<<"NO";

}
