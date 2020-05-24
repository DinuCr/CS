#include <bits/stdc++.h>

using namespace std;

#define ll long long

const int N = 40400;

ll x, y, len;
ll v[N];
ll i, a, b, q;

ll compute (ll x)
{
    ll r = x % len;
    ll d = x / len;
    ll ans = d * v[len - 1] + v[r];

    return x - ans;
}

int main()
{
    int T = 1;
    cin >> T;
    while (T--)
    {
        memset(v, 0, sizeof(v));

        cin >> a >> b >> q;

        len = 1LL * a * b;
        v[0] = 1;
        for (i = 0; i < a * b; ++i)
        {
            if ( (i % a) % b == (i % b) % a )
            {
                v[i] = 1;
            }
            v[i] += v[i - 1];
        }

        while(q--)
        {
            cin >> x >> y;
            cout << compute(y) - compute(x - 1) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
