#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

char v[1000];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    cin>>t;
    for(int cnt=1; cnt<=t; ++cnt)
    {
        string s;
        cin>>s;
        memset(v, 0, sizeof(v));
        for(int i=0; i<s.length(); ++i)
            if(s[i]=='4')
                s[i]='2',v[i]='2';
        cout<<"Case #"<<cnt<<": "<<s<<' ';
        int ok=0;
        for(int i=0; i<s.length(); ++i)
            if(ok || v[i]!=0)
                ok=1,cout<<((v[i]==0)?('0'):v[i]);
        cout<<'\n';
    }
}
