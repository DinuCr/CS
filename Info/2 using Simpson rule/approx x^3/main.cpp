#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

double x[(int)1LL<<20],y[(int)1LL<<20];

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int i,n;
    double sum = 0;
    cout<<"Type in n,(power of 2)\n";
    cin>>n;
    double h = (double)2/n;
    for(i=1; i<=n; ++i)
        x[i]= i*h, y[i]=(double) pow(x[i],1.5);
    for(i=1; i<=n-1; i+=2)
        sum = sum + 4 * y[i];
    for(i=2; i<n-1; i+=2)
        sum = sum + 2 * y[i];
    double integral = (h/3) * (y[0] + sum + y[n]);
    cout<<integral;
}
