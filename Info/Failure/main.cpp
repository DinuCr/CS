#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

string a, b, c;
int val[300];
int used[300];
int in_use[300];
vector <int> v;
vector <pair<pair<int,int>, int> > lim;
int last_a, last_b, last_c;

vector <vector <int> > ans;

void add_zeros()
{
    int mx = max(a.length(), max(b.length(), c.length()));

    for(int i=0; i<mx; ++i)
    {
        if(a.length()<=i)
            a.append("0");
        if(b.length()<=i)
            b.append("0");
    }
}

void set_conditions()
{
    for(int i=0; i<c.length(); ++i)
    if(a[i]!='0' && b[i]!='0')
    {
        lim.pb(mp(mp(a[i],b[i]),c[i]));
    }
}

bool check()
{
    int carry = 0;
    for(int i=0; i<c.length(); ++i)
    {
        if((val[a[i]]+val[b[i]]+carry)%10!=val[c[i]])
            return 0;
        carry = (val[a[i]]+val[b[i]])/10;
    }
    if(carry)
        return 0;
    return 1;
}

void add_sol()
{
    vector <int> curr;
    int i=0;
    for(i=0; i<a.length(); ++i)
        if(a[i]!='0')
            curr.pb(val[a[i]]);
    reverse(curr.begin(), curr.end());
    ans.pb(curr);
    curr.clear();

    for(i=0; i<b.length(); ++i)
        if(b[i]!='0')
            curr.pb(val[b[i]]);
    reverse(curr.begin(), curr.end());
    ans.pb(curr);
    curr.clear();

    for(i=0; i<c.length(); ++i)
        if(c[i]!='0')
            curr.pb(val[c[i]]);
    reverse(curr.begin(), curr.end());
    ans.pb(curr);
    curr.clear();
}

bool check_conditions()
{
    if(in_use[last_a] && val[last_a]==0)
        return 0;
    if(in_use[last_b] && val[last_b]==0)
        return 0;
    if(in_use[last_c] && val[last_c]==0)
        return 0;

    for(auto it:lim)
    {
        if(in_use[it.f.f] && in_use[it.f.s] && in_use[it.s])
        {
            if((val[it.f.f]+val[it.f.s])%10==val[it.s] ||
               (val[it.f.f]+val[it.f.s])%10==(val[it.s]-1)%10 )
                continue;
            else
                return 0;
        }
    }
    return 1;
}

void bkt(int k)
{
    if(k==v.size())
    {
        if(check())
            add_sol();
        return ;
    }

    if(k==1 && val[v[0]]==5)
    {
        cout<<'d';
    }

    for(int i=0; i<10;  ++i)
    {
        in_use[v[k]]=1;
        val[v[k]]=i;
        if(check_conditions())
            bkt(k+1);
        in_use[v[k]]=0;
    }
}

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin>>a>>b>>c;

    int i;

    last_a = a[0];
    last_b = b[0];
    last_c = c[0];

    for(i=0; i<a.length()/2; ++i)
        swap(a[i],a[a.length()-i-1]);
    for(i=0; i<b.length()/2; ++i)
        swap(b[i],b[b.length()-i-1]);
    for(i=0; i<c.length()/2; ++i)
        swap(c[i],c[c.length()-i-1]);

    if(c.length()<max(a.length(),b.length()) || c.length()>max(a.length(),b.length())+1)
    {
        cout<<"not possible";
        return 0;
    }

    add_zeros();

    set_conditions();

    used['0'] = 1;

    for(i=0; i<a.length(); ++i)
        if(!used[a[i]])
        {
            used[a[i]]=1;
            v.pb(a[i]);
        }
    for(i=0; i<b.length(); ++i)
        if(!used[b[i]])
        {
            used[b[i]]=1;
            v.pb(b[i]);
        }
    for(i=0; i<c.length(); ++i)
        if(!used[c[i]])
        {
            used[c[i]]=1;
            v.pb(c[i]);
        }

    bkt(0);

    if(ans.size()==0)
        cout<<"not possible";
    else
    {
        cout<<ans.size()/3<<'\n';
        int cnt = 0;
        for(auto w:ans)
        {
            ++cnt;
            for(auto it:w)
                cout<<it;
            cout<<'\n';
            if(cnt%3==0)
                cout<<'\n';
        }
    }
}
