#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("patrate1.in");
ofstream fout("patrate1.out");

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int l,h,x,y;

    fin>>l>>h>>x>>y;
    int ans = 1 + (x-1)/l + (y-1)/h;
    int step = y*l/gcd((ll)x*h,(ll)y*l);
    ans -= (y-1)/step/h;
    fout<<ans;
}
