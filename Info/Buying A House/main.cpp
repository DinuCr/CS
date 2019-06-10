#include <iostream>

using namespace std;

int main()
{
    int v[110];
    int n,i,m,k;
    cin>>n>>m>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    int a = m-1;
    int b = m+1;
    while(a>0 || b<=n)
    {
        if(a>0)
            if(v[a] && v[a]<=k)
            {
                cout<<(m-a)*10;
                return 0;
            }
        if(b<=n)
            if(v[b] && v[b]<=k)
            {
                cout<<(b-m)*10;
                return 0;
            }
        --a;
        ++b;
    }
}
