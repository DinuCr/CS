#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

char v[10];
int k,i,j,p;

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>k;

    v[1]='a';
    v[2]='e';
    v[3]='i';
    v[4]='o';
    v[5]='u';

    for(i=sqrt(k); i>0; --i)
    {
        if(k%i==0)
            break;
    }
    if(i>=5 && k/i>=5)
    {
        for(j=1; j<=k/i; ++j)
        {
            for(p=1; p<=i; ++p)
                cout<<v[(j+p-2)%5+1];
        }
    }
    else
    cout<<"-1";
}
