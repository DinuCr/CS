#include <iostream>
#include <bits/stdc++.h>

using namespace std;

vector<string> v[25];

int main()
{
    int n;
    cin>>n;
    int curr = 0;
    int p = 0;
    while(n--)
    {
        string a;
        cin>>a;
        ++p;
        curr = p;
        for(int j=1; j<p; ++j)
            if(v[j][0]==a)
                curr = j,--p;

        if(v[curr].size()==0)
            v[curr].push_back(a);
        int m;
        cin>>m;
        for(int j=1; j<=m; ++j)
        {
            cin>>a;
            reverse(a.begin(),a.end());
            v[curr].push_back(a);
        }
        sort(v[curr].begin()+1,v[curr].end());
        for(int i=2; i<v[curr].size(); ++i)
        {
            if(v[curr][i-1]==v[curr][i])
                v[curr].erase(v[curr].begin()+i-1),--i;
            else
            {
                if(v[curr][i].length()>v[curr][i-1].length())
                {
                    int ok = 1;
                    for(int a=0; a<v[curr][i-1].length(); ++a)
                        if(v[curr][i][a]!=v[curr][i-1][a])
                            ok=0;
                    if(ok)
                        v[curr].erase(v[curr].begin()+i-1),--i;
                }
            }
        }
    }
    cout<<p<<'\n';
    while(p>0)
    {
        cout<<v[p][0]<<' '<<v[p].size()-1<<' ';
        for(int i=1; i<v[p].size(); ++i)
        {
            reverse(v[p][i].begin(),v[p][i].end());
            cout<<v[p][i]<<' ';
        }
        cout<<'\n';
        --p;
    }
}
