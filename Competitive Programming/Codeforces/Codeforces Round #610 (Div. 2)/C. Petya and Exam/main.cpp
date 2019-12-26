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

    int t;
    cin>>t;
    while(t--)
    {
        int n,T,a,b;
        int ez=0,hard=0;
        vector <pair<int,int> >v;
        cin>>n>>T>>a>>b;
        for(int i=0; i<n; ++i)
        {
            int x;
            cin>>x;
            v.pb(mp(0,x));
            if(x==0)
                ez++;
            else
                hard++;
        }
        for(int i=0; i<n; ++i)
            cin>>v[i].f;

        sort(v.begin(),v.end());

        int curr = 0;
        int currt = 0;
        int ans = 0;
        for(auto it:v)
        {
            if(currt<it.f)
                ans = max(ans,curr);
            if(currt<it.f)
            {
                it.f--;
                int curr2 = curr;
                int currt2 = currt;
                curr2 += min(ez, (it.f-currt2)/a);
                currt2 += min(ez, (it.f-currt2)/a)*a;
                if(currt2<it.f)
                    curr2 += min(hard, (it.f-currt2)/b);
                ans=max(ans, curr2);
                it.f++;
            }
            if(it.s==0)
                currt += a, ez--;
            else
                currt += b, hard--;
            if(currt>T)
                break;
            curr++;
        }
        if(currt<=T)
            ans=max(ans,curr);
        cout<<ans<<'\n';
    }
}
