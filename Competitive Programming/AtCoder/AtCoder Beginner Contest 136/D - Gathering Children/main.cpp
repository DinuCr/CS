#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[100100],r[100100],l[100100];
string s;
int i;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>s;

    int n = s.length();

    for(i=0; i<n; ++i)
    {
        if(s[i]=='R')
            r[i]=i;
        else
            r[i]=r[i-1];
    }
    for(i=n-1; i>=0; --i)
    {
        if(s[i]=='L')
            l[i]=i;
        else
            l[i]=l[i+1];
    }
    for(i=0; i<n; ++i)
    {
        if(s[i]=='R')
        {
            if((l[i]-i)%2==0)
                v[l[i]]++;
            else
                v[l[i]-1]++;
        }
        else
        {
            if((i-r[i])%2==0)
                v[r[i]]++;
            else
                v[r[i]+1]++;
        }
    }
    for(i=0; i<n; ++i)
        cout<<v[i]<<' ';
}
