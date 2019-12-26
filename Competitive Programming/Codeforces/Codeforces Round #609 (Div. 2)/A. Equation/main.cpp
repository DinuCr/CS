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

    int n;
    cin>>n;
    int a = 4;
    int b = n+4;
    for( ; ; ++a,++b)
    {
        if((a%2==0 || a%3==0) && (b%2==0 || b%3==0))
            break;
    }
    cout<<b<<' '<<a;
}
