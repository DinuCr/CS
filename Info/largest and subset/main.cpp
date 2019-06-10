#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e5+10

int v[nmax];
int n,k,i,j;

int main()
{
    cin>>n>>k;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    vector <int> ans;
    for(j=30; j>=0; --j)
    {
        vector <int> curr;
        if(ans.empty())
        {
            for(i=1; i<=n; ++i)
                if((1<<j) & v[i])
                    curr.push_back(v[i]);
        }
        else
        for(auto it:ans)
        {
            if(it & (1<<j))
                curr.push_back(it);
        }
        if(curr.size()>=k)
        {
            ans.clear();
            ans.swap(curr);
        }
    }
    int r = (1<<31)-1;
    for(auto it:ans)
        r&=it;
    if(ans.empty())
        r=0;
    cout<<r;
}
