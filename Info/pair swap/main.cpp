#include <iostream>
#include <deque>

using namespace std;

#define nmax (int)1e5+10

deque <int> q;
int v[nmax];
int d[nmax];

int main()
{
    int i,n,k;
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=n+k; ++i)
    {
        while(!q.empty() && q.front()<i-k)
            q.pop_front();
        while(!q.empty() && i<=n && v[q.back()]>=v[i])
            q.pop_back();
        if(i<=n)
        q.push_back(i);
        if(i>k)
        {
            if(q.empty())
                d[i-k]=i-k;
            else
                d[i-k]=q.front();
        }
    }
    for(i=1; i<=n; ++i)
        if(v[d[i]]<v[i])
        {
            swap(v[i],v[d[i]]);
            break;
        }
    for(i=1; i<=n; ++i)
        cout<<v[i]<<' ';
}
