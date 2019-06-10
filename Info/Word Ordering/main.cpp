#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <string> v;
int order[200];
int n;

bool compare(string a,string b)
{
    for(int i=0; i<min(a.length(),b.length()); ++i)
        if(a[i]!=b[i])
            return order[a[i]]<order[b[i]];
    return a.length()<b.length();
}

int main()
{
    string s;
    cin>>s;
    for(int i=0; i<s.length(); ++i)
    {
        order[s[i]]=i;
        order[s[i]+'a'-'A']=30+i;
    }
    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),compare);
    for(auto it:v)
        cout<<it<<'\n';
}
