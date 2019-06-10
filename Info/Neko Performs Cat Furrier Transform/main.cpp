#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

vector <int> ans;
int i,cnt,nr,x;

int check(int x)
{
    int i=1;
    while(i<=x)
    {
        if(i==x)
            return 1;
        i=(i+1)*2-1;
    }
    return 0;
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>x;
    int ok=0;
    int nr = 0;
    for(cnt = 1; cnt<=x; cnt<<=1);
    while(!ok)
    {
        if(check(x))
            break;
        cnt>>=1;
        if(x&(cnt>>1))
            continue;
        ans.pb(log2(cnt));
        x = x ^ (cnt - 1);
        ++nr;
        if(check(x))
            break;
        x++;
        ++nr;
    }
    cout<<nr<<'\n';
    for(auto it:ans)
        cout<<it<<' ';
}
