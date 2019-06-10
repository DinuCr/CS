#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back
int n, last;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    int lastlast=0;
    cin>>last;
    ll ans = 0;
    int ok = 0;
    for(int i=1; i<n; ++i)
    {
        int x;
        cin>>x;
        if((last==1 && x==2))
            ans+=3-(lastlast==3);
        else
        if(last==1 && x==3)
            ans+=4;
        else
        if(last==2 && x==1)
            ans+=3;
        else
        if(last==2 && x==3)
            ok=1;
        else
        if(last==3 && x==1)
            ans+=4;
        else
            ok=1;
        lastlast=x;
        last=x;

    }
    if(ok)
        cout<<"Infinite";
    else
        cout<<"Finite\n"<<ans;
}
