#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

vector <vector <int> >v;

bool cmp(vector <int> a,vector <int> b)
{
    for(int i=0; i<26; ++i)
        if(a[i]!=b[i])
            return a[i]<b[i];
    return 0;
}

bool egal(vector <int> a,vector <int> b)
{
    for(int i=0; i<26; ++i)
        if(a[i]!=b[i])
            return false;
    return true;
}

int main()
{
    int i,n;

    cin.sync_with_stdio(0);
    cout.sync_with_stdio(0);

    string s;

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        vector <int> curr;

        cin>>s;
        for(int j=1; j<=26; ++j)
            curr.push_back(0);
        for(int j=0; j<s.length(); ++j)
            ++curr[s[j]-'a'];
        v.push_back(curr);
    }

    sort(v.begin(),v.end(),cmp);
    int curr = 1,ans = 1;
    for(i=1; i<n; ++i)
    {
        if(egal(v[i],v[i-1]))
            ++curr;
        else
            curr=1;
        ans=max(ans,curr);
    }
    cout<<ans;
}
