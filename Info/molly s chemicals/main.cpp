#include <iostream>
#include <unordered_map>

using namespace std;

#define ll long long

unordered_map <ll, int> q;
ll i,n,k,z,ans,sum,x;

inline ll abso(ll a)
{
    if(a<0)
        return -a;
    return a;
}

int main()
{
    cin>>n>>k;
    q[0]=1;
    q.reserve(666667);
    for(i=1; i<=n; ++i)
    {
        cin>>x;
        sum+=x;
        if(k!=1 && k!=-1)
        {
            for(z=1; abso(z)<=(ll)(1e17); z*=k)
                if(q.find(sum-z)!=q.end())
                {
                    ans+=q[sum-z];
                }
        }
        else
        {
            if(k==1)
            {
                if(q.find(sum-k)!=q.end())
                    ans+=q[sum-k];
            }
            else
            {
                if(q.find(sum-1)!=q.end())
                    ans+=q[sum-1];
                if(q.find(sum+1)!=q.end())
                    ans+=q[sum+1];
            }
        }
        q[sum]++;
    }
    cout<<ans;
}
