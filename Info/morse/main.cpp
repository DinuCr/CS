#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

string s[30];
char curr[100010];
string v[100010];

int main()
{
    int i,n,j,ans,cnt;
    for(i=0; i<26; ++i)
    {
        char c;
        cin>>c;
        cin>>s[c-'a'];
    }
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>curr;
        int m = strlen(curr);
        for(j=0; j<m; ++j)
            v[i].insert(v[i].size(),s[curr[j]-'a']);
    }
    sort(v+1,v+n+1);
    ans = 1;
    cnt = 1;
    for(i=2; i<=n; ++i)
        if(!v[i].compare(v[i-1]))
            ++cnt;
        else
        {
            ans = max(ans,cnt);
            cnt = 1;
        }
    ans = max(ans,cnt);
    if(ans==1)
        ans=-1;
    cout<<ans;
}

