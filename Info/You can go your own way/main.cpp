#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define si second
#define pb push_back

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    cin>>t;
    for(int cnt=1; cnt<=t; ++cnt)
    {
        string s;
        int x;
        cin>>x;
        cin>>s;
        for(int i=0; i<s.length(); ++i)
            if(s[i]=='E')
                s[i]='S';
            else
                s[i]='E';
        cout<<"Case #"<<cnt<<": "<<s<<'\n';
    }
}
