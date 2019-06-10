#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e5+10

string s;
int d[nmax];

string rollTheString(string s, vector <int> roll) {
    int d[(int)1e5+10];
    memset(d,0,sizeof(d));
    for(auto it:roll)
        ++d[0],--d[it];
    long long curr = 0;
    string ans(s.length(),'a');
    for(int i=0; i<s.length(); ++i)
    {
        curr+=d[i];
        ans[i]=(char)(1LL*(s[i]-'a')+curr)%26+'a';
    }
    return ans;
}


int main()
{
    int m;
    cin>>s;
    cin>>m;
    vector <int> roll;
    while(m--)
    {
        int x;
        cin>>x;
        roll.push_back(x);
    }
    cout<<rollTheString(s,roll);
}
