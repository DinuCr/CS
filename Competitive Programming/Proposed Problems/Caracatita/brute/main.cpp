#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair

ifstream fin("9-caracatita.in");
ofstream fout("9-caracatita.ok");

const int nmax = 510;

vector <pair<char, int> > v[nmax];


int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n,m;

    fin>>n;
    for(int i=0; i<n; ++i)
    {
        string s;
        fin>>s;
        char last = 0;
        for(auto it:s)
            if(last!=it)
                last=it,v[i].pb(mp(it,1));
            else
                v[i].back().s++;
    }

    fin>>m;

    while(m--)
    {
        string s;
        fin>>s;
        char last = 0;
        vector <pair<char, int> > curr;

        for(auto it:s)
            if(last!=it)
                last=it,curr.pb(mp(it,1));
            else
                curr.back().s++;

        int ans = 0;

        for(int k=0; k<n; ++k)
        {
            int a = 0;
            int b = 0;
            int ok = 0;
            int aux = curr[a].s;
            while(a<curr.size() && b<v[k].size())
            {
                if(curr[a].f == v[k][b].f)
                {
                    aux -= v[k][b].s;
                    if(aux<=0)
                    {
                        ++a;
                        if(a<curr.size())
                            aux = curr[a].s;
                    }
                }
                ++b;
            }

            if(a==curr.size())
                ok = 1;

            if(ok)
            {
                int cnt = 0;
                for(int i=0; i<v[k].size()-curr.size()+1; ++i)
                {
                    int check = 1;
                    for(int j=0; j<curr.size(); ++j)
                        if(v[k][i+j].f!=curr[j].f)
                            check = 0;
                    cnt += check;
                }
                ans += cnt;
            }
        }

        fout<<ans<<'\n';
    }
}
