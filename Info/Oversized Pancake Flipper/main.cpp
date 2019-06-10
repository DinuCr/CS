#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("pancake.in");
ofstream fout("pancake.out");

char v[1010];

void change(int x)
{
    if(v[x]=='+')
        v[x]='-';
    else
        v[x]='+';
}

int main()
{
    int t,i,j;
    fin>>t;
    int cnt = 1;
    while(t--)
    {
        int k,n;
        string s;
        fin>>s>>k;
        for(int i=0; i<s.size(); ++i)
            v[i+1]=s[i];
        n = s.size();
        n-=k-1;
        int ans = 0;
        for(i=1; i<=n; ++i)
            if(v[i]=='-')
            {
                ++ans;
                for(j=0; j<k; ++j)
                    change(j+i);
            }
        int ok = 1;
        for(i=1; i<k; ++i)
            if(v[i+n]=='-')
                ok=0;
        if(ok)
            fout<<"Case #"<<cnt<<": "<<ans<<'\n';
        else
            fout<<"Case #"<<cnt<<": "<<"IMPOSSIBLE"<<'\n';

        ++cnt;
    }
}
