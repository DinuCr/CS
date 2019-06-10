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

    int n,i,neg=0,zero=0,pos=0;

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        if(x<0)
            neg++;
        else
        if(x==0)
            zero++;
        else
            pos++;
    }
    if(pos>=ceil((double)n/2))
        cout<<1;
    else
    if(neg>=ceil((double)n/2))
        cout<<-1;
    else
        cout<<0;
}
