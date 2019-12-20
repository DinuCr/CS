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

    ll n,p,w,d;

    cin>>n>>p>>w>>d;

    int ok =0;

    if(p==0)
    {
        cout<<0<<' '<<0<<' '<<n;
        return 0;
    }

    ll mod = (n*w-p)%(w-d);

    if(mod==0)
    {
        ll b = (n*w - p) / (w-d);
        ll a = n-b;
        if(a>=0 && b>=0)
        {
            cout<<a<<' '<<b<<' '<<0;
            return 0;
        }
    }

    ll c = (n*w-p)/w;

    ll z = (c*w)%(w-d);

    ll c2 = 1;

    ll z2 = (c2*w)%(w-d);

    do
    {
        if (ok==3)
            break;
        if(c<0 || n*w-p-c2<0)
            break;



        if(z==mod)
        {
            ll b = (n*w - p - c*w) / (w-d);
            ll a = n-b-c;
            if(a>=0 && b>=0)
            {
                cout<<a<<' '<<b<<' '<<c;
                return 0;
            }
            ok|=1;
        }


        if(z2==mod)
        {
            ll b = (n*w - p - c2*w) / (w-d);
            ll a = n-b-c2;
            if(a>=0 && b>=0)
            {
                cout<<a<<' '<<b<<' '<<c2;
                return 0;
            }
            ok|=2;
        }

        ll z3;

        --c;
        z3 = (c*w)%(w-d);

        if(z==z3)
            break;

        z=z3;

        ++c2;
        z3 = (c2*w)%(w-d);

        if(z2==z3)
            break;

        z2=z3;
    }
    while(true);

    cout<<-1;
}
