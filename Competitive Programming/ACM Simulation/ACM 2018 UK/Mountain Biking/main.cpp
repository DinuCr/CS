#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int v[100],w[100];

const double PI = 3.14159265;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int n,i,j;
    double g;

    cin>>n>>g;
    for(i=1; i<=n; ++i)
        cin>>v[i]>>w[i];

    for(i=1; i<=n; ++i)
    {
        double speed = 0;
        double speed0 = 0;
        for(j=i; j<=n; ++j)
        {
            speed = sqrt(speed0*speed0 + 2 * v[j] * g * cos(w[j] * PI / 180.0));
            speed0 = speed;
        }
        cout<<setprecision(10)<<fixed<<speed<<'\n';
    }
}
