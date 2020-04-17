#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

ifstream fin("");
ofstream fout("");

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
    {
        int a,b,c,x;
        cin>>a>>b>>c;
        vector <int> v1;
        vector <int> v2;
        vector <int> v3;
        for(int i=1; i<=a; ++i)
        {
            cin>>x;
            v1.pb(x);
        }
        for(int i=1; i<=b; ++i)
        {
            cin>>x;
            v2.pb(x);
        }
        for(int i=1; i<=c; ++i)
        {
            cin>>x;
            v3.pb(x);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());
        sort(v3.begin(), v3.end());

        ll ans = 1e19;

        for(auto it:v1)
        {
            ll a = it;
            ll b1, b2, c1, c2;

            vector <int> ::iterator aux = lower_bound(v2.begin(), v2.end(), a);

            if(aux == v2.end())
            {
                aux --;
                b1 = b2 = *aux;
            }
            else
            if(aux == v2.begin())
            {
                b1 = b2 = *aux;
            }
            else
            {
                b1 = *aux;
                aux --;
                b2 = *aux;
            }

            aux = lower_bound(v3.begin(), v3.end(), a);

            if(aux == v3.end())
            {
                aux --;
                c1 = c2 = *aux;
            }
            else
            if(aux == v3.begin())
            {
                c1 = c2 = *aux;
            }
            else
            {
                c1 = *aux;
                aux --;
                c2 = *aux;
            }

            ll curr1 = (a-b1)*(a-b1) + (a-c1)*(a-c1) + (b1-c1)*(b1-c1);
            ll curr2 = (a-b2)*(a-b2) + (a-c1)*(a-c1) + (b2-c1)*(b2-c1);
            ll curr3 = (a-b1)*(a-b1) + (a-c2)*(a-c2) + (b1-c2)*(b1-c2);
            ll curr4 = (a-b2)*(a-b2) + (a-c2)*(a-c2) + (b2-c2)*(b2-c2);

            ans = min(ans, curr1);
            ans = min(ans, curr2);
            ans = min(ans, curr3);
            ans = min(ans, curr4);
        }

        for(auto it:v2)
        {
            ll a = it;
            ll b1, b2, c1, c2;

            vector <int> ::iterator aux = lower_bound(v1.begin(), v1.end(), a);

            if(aux == v1.end())
            {
                aux --;
                b1 = b2 = *aux;
            }
            else
            if(aux == v1.begin())
            {
                b1 = b2 = *aux;
            }
            else
            {
                b1 = *aux;
                aux --;
                b2 = *aux;
            }

            aux = lower_bound(v3.begin(), v3.end(), a);

            if(aux == v3.end())
            {
                aux --;
                c1 = c2 = *aux;
            }
            else
            if(aux == v3.begin())
            {
                c1 = c2 = *aux;
            }
            else
            {
                c1 = *aux;
                aux --;
                c2 = *aux;
            }

            ll curr1 = (a-b1)*(a-b1) + (a-c1)*(a-c1) + (b1-c1)*(b1-c1);
            ll curr2 = (a-b2)*(a-b2) + (a-c1)*(a-c1) + (b2-c1)*(b2-c1);
            ll curr3 = (a-b1)*(a-b1) + (a-c2)*(a-c2) + (b1-c2)*(b1-c2);
            ll curr4 = (a-b2)*(a-b2) + (a-c2)*(a-c2) + (b2-c2)*(b2-c2);

            ans = min(ans, curr1);
            ans = min(ans, curr2);
            ans = min(ans, curr3);
            ans = min(ans, curr4);
        }

        for(auto it:v3)
        {
            ll a = it;
            ll b1, b2, c1, c2;

            vector <int> ::iterator aux = lower_bound(v2.begin(), v2.end(), a);

            if(aux == v2.end())
            {
                aux --;
                b1 = b2 = *aux;
            }
            else
            if(aux == v2.begin())
            {
                b1 = b2 = *aux;
            }
            else
            {
                b1 = *aux;
                aux --;
                b2 = *aux;
            }

            aux = lower_bound(v1.begin(), v1.end(), a);

            if(aux == v1.end())
            {
                aux --;
                c1 = c2 = *aux;
            }
            else
            if(aux == v1.begin())
            {
                c1 = c2 = *aux;
            }
            else
            {
                c1 = *aux;
                aux --;
                c2 = *aux;
            }

            ll curr1 = (a-b1)*(a-b1) + (a-c1)*(a-c1) + (b1-c1)*(b1-c1);
            ll curr2 = (a-b2)*(a-b2) + (a-c1)*(a-c1) + (b2-c1)*(b2-c1);
            ll curr3 = (a-b1)*(a-b1) + (a-c2)*(a-c2) + (b1-c2)*(b1-c2);
            ll curr4 = (a-b2)*(a-b2) + (a-c2)*(a-c2) + (b2-c2)*(b2-c2);

            ans = min(ans, curr1);
            ans = min(ans, curr2);
            ans = min(ans, curr3);
            ans = min(ans, curr4);
        }
        cout<<ans<<'\n';
    }

}

/*
#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define mp make_pair
#define pb push_back
#define ll long long

ifstream fin("");
ofstream fout("");

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);

	int t;
	cin>>t;
	while(t--)
    {
        int x;
        int n,m,k;
        cin>>n>>m>>k;

        vector <ll> a;
        vector <ll> b;
        vector <ll> c;
        for(int i=1; i<=n; ++i)
        {
            cin>>x;
            a.pb(x);
        }
        for(int i=1; i<=m; ++i)
        {
            cin>>x;
            b.pb(x);
        }
        for(int i=1; i<=k; ++i)
        {
            cin>>x;
            c.pb(x);
        }

        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        sort(c.begin(), c.end());

        x = 0;
        int y = 0;
        int z = 0;

        ll ans = 1e19;

        while(x<a.size() && y<b.size() && z<c.size())
        {
            ll curr = (a[x]-b[y])*(a[x]-b[y]) + (a[x]-c[z])*(a[x]-c[z]) + (b[y]-c[z])*(b[y]-c[z]);
            ans = min(ans,curr);

            if(a[x] < min(b[y], c[z]))
            {
                if(x<a.size()-1)
                    ++x;
                else
                if(b[y]<c[z])
                    ++y;
                else
                    ++z;
            }
            else
            if(b[y] < min(a[x], c[z]))
            {
                if(y<b.size()-1)
                    ++y;
                else
                if(a[x]<c[z])
                    ++x;
                else
                    ++z;
            }
            else
            {
                if(z<c.size()-1)
                    ++z;
                else
                if(a[x]<b[y])
                    ++x;
                else
                    ++y;
            }
        }
        cout<<ans<<'\n';
    }

}

*/
