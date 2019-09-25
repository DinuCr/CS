#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ll x1,x2,x3,x4,x5,x6;
ll y1,y2,y3,y4,y5,y6;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>x1>>y1>>x2>>y2;
    cin>>x3>>y3>>x4>>y4;
    cin>>x5>>y5>>x6>>y6;

    ll size1 = 0;
    ll size2 = 0;
    ll size3 = 0;
    ll a,b;

    a = min(x2,x4) - max(x1,x3);
    b = min(y2,y4) - max(y1,y3);
    if(a<0 || b<0)
        size1=0;
    else
        size1 = a*b;

    a = min(x2,x6) - max(x1,x5);
    b = min(y2,y6) - max(y1,y5);
    if(a<0 || b<0)
        size3=0;
    else
        size3 = a*b;

    ll c,d,e,f;
    a = max(x3,x5);
    b = min(x4,x6);
    c = max(y3,y5);
    d = min(y4,y6);
    if(a<b && c<d)
    {
        e = min(x2,b) - max(x1,a);
        f = min(y2,d) - max(y1,c);
        if(e<0 || f<0)
            size2=0;
        else
            size2=e*f;
    }
    else
        size2 = 0;


    if(size1 + size3 !=0 && size1 + size3 - size2 == (y2-y1)*(x2-x1))
        cout<<"NO";
    else
        cout<<"YES";

}

