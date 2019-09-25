#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,cnt=0,i;
    char v[201000];

    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=1; i<=n; i+=2)
    {
        if(v[i]+v[i+1]!='a'+'b')
        {
            if(v[i]=='a')
                v[i]='b';
            else
                v[i]='a';
            cnt++;
        }
    }
    cout<<cnt<<'\n';
    for(i=1; i<=n; ++i)
        cout<<v[i];

}
