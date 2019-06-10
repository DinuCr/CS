#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector <int> ans;
int n,i,a,b;

int next_prime(int x)
{
    for(int j=x+1; ; ++j)
    {
        int ok=0;
        int k = sqrt(j);
        for(i=2; i<=k; i+=2)
            if(j%i==0)
            {
                ok=1;
                break;
            }
        if(ok==0)
            return j;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int x;
        cin>>x;
        if(x==1)
            a++;
        else
            b++;
    }
    int prime=2;
    int curr = 0;
    while(a || b)
    {
        if(a && b)
        {
            if(prime-curr>=2)
            {
                ans.pb(2);
                curr+=2;
                --b;
            }
            else
            {
                --a;
                ans.pb(1);
                curr++;
            }
        }
        else
        {
            if(b)
                ans.pb(2),b--,curr++;
            else
            if(a)
                ans.pb(1),a--,curr++;
        }
        if(curr>=prime)
            prime=next_prime(prime);
    }
    for(auto it:ans)
        cout<<it<<' ';

}
