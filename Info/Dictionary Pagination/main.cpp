#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector <string> v;
string s;

int main()
{
    int n,m,p;
    cin>>n>>m;
    while(n--)
    {
        cin>>s;
        v.push_back(s);
    }
    sort(v.begin(),v.end());
    while(m--)
    {
        cin>>s>>p;
        int poz = lower_bound(v.begin(),v.end(),s)-v.begin()+1;
        cout<<(poz-1)/p+1<<'\n';
    }
}
