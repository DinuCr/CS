#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

vector <int> v;
int n, a,b,i,x;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        char c;
        cin>>c;
        if(c=='W')
            c='0';
        else
            c='1';
        v.pb(c-'0');
        if(v.back()==1)
            a++;
        else
            b++;
    }
    if(a%2==1 && b%2==1)
    {
        cout<<-1;
        return 0;
    }
    vector <pair<int,int> > ans;

    if(a%2==0 && b%2==0)
    {
        if(a<b)
            x = 1;
        else
            x = 0;
    }
    else
    if(a%2==0)
        x = 1;
    else
        x = 0;

    int last = -1;
    for(int i=0; i<v.size(); ++i)
    {
        if(v[i]==x)
        {
            if(last==-1)
                last = i;
            else
            {
                for(int j=i; j>last+1; --j)
                    ans.pb(mp(j,j+1));
                ans.pb(mp(last+1, last+2));
                last = -1;
            }
        }
    }
    cout<<ans.size()<<'\n';
    for(auto it:ans)
        cout<<it.f<<' ';
}
