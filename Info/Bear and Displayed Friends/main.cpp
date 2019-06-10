#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> q;
int v[150100],p,i,k,t,n,ok,j;
bool compare(int a,int b)
{
    return v[a]>v[b];
}
int main()
{
    cin>>n>>k>>t;
    for(i=1;i<=n;i++)
        cin>>v[i];
    for(i=1;i<=t;i++)
    {
        cin>>p;
        switch(p)
        {
        case 1:
            cin>>p;
            q.push_back(p);
            sort(q.begin(),q.end(),compare);
            if(q.size()>k)
                q.pop_back();
            break;
        case 2:
            cin>>p;ok=0;
            for(j=0;j<q.size();j++)
                if(q[j]==p)
                ok=1;
            if(ok)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
    }
}
