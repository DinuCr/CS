#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

ifstream fin("pinex.in");
ofstream fout("pinex.out");

#define nmax 1000010
#define ll long long

long long ciur[nmax];
vector <long long> v;

int main()
{
    long long i,j,q;
    ll a,b;
    for(i=4; i<1e6; i+=2)
        ciur[i]=1;
    for(i=3; i<=1e3; i+=2)
        if(!ciur[i])
            for(j=i*i; j<=1e6; j+=i)
                ciur[j]=1;
    for(i=2; i<=1e6; ++i)
        if(!ciur[i])
            v.push_back(i);
    v.push_back(1e9);
    fin>>q;
    while(q--)
    {
        ll ans = 0;
        fin>>a>>b;
        vector <long long> curr;
        long long lim = sqrt(b);
        for(auto it:v)
        {
            if(it>lim || it>b)
                break;
            if(b%it==0)
            {
                curr.push_back(it);
                b/=it;
                while(b%it==0)
                    b/=it;
            }
        }
        if(b>1)
            curr.push_back(b);

        lim = (1<<(curr.size()));
        for(i=1; i<lim; ++i)
        {
            ll nr = 1, ok = 0;
            for(j=0; j<curr.size(); ++j)
                if((1<<j)&i)
                    nr*=curr[j],++ok;
            if(ok&1)
                ans += a/nr;
            else
                ans -= a/nr;
        }
        fout<<a-ans<<'\n';
    }
}
