#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

int dif(char a, char b)
{
    int x = min(abs(b-a),26-(abs(b-a)));
    return x;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);


    int n;
    string s;

    cin>>n;
    cin>>s;
    int mn = 100000;
    for(int i=0; i<n-3; ++i)
    {
        mn = min(mn, dif('A',s[i]) + dif('C',s[i+1]) + dif('T',s[i+2]) + dif('G',s[i+3]));
    }
    cout<<mn;
}
