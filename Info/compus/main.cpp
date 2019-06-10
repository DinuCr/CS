#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("compus.in");
ofstream fout("compus.out");

deque <int> q;
int mx,n;
int v[1000100],i,ans;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    ans=1;
    for(i=3; i<=n; i+=2)
    {
        mx=max(mx,v[(i+1)/2-1]);
        if(q.size())
            q.pop_front();
        while(q.size() && q.front()>=v[i-1])
            q.pop_back();
        q.push_back(v[i-1]);
        while(q.size() && q.front()>=v[i])
            q.pop_back();
        q.push_back(v[i]);
        if(v[(i+1)/2]>=mx && v[(i+1)/2]<=q.front())
            ans=max(ans,i);
    }
    fout<<ans;
}
