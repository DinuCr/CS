#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define nmax 55

ifstream fin("luna.in");
ofstream fout("luna.out");

set <pair<int,int> >available[5010];
int v[nmax][nmax];
int dx[nmax][nmax];

#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
     numar = 0;
     //cat timp caracterul din buffer nu e cifra ignor
     while (buff[poz] < '0' || buff[poz] > '9')
          //daca am "golit" bufferul atunci il umplu
          if (++poz == DIM)
               fin.read(buff,DIM),poz=0;
     //cat timp dau de o cifra recalculez numarul
     while ('0'<=buff[poz] && buff[poz]<='9')
     {
          numar = numar*10 + buff[poz] - '0';
          if (++poz == DIM)
               fin.read(buff,DIM),poz=0;
     }
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    string can = "Cererea poate fi satisfacuta!\n";
    string cannot = "Cererea nu poate fi satisfacuta!\n";
    string not_existent = "Tara de provenienta nu are parcele pe Luna!\n";

    int n,m,i,j,k;
    citeste(n);
    citeste(m);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            citeste(v[i][j]);
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            if(v[i][j]==v[i-1][j])
                dx[i][j]=dx[i-1][j]+1;
            else
                dx[i][j]=1;
            int curr = dx[i][j], l = 1;
            available[v[i][j]].insert(mp(curr,l));
            for(k=j-1; k>0 && v[i][k]==v[i][j]; --k)
            {
                ++l;
                curr=min(curr,dx[i][k]);
                if(curr>l)
                    available[v[i][j]].insert(mp(curr,l));
                else
                    available[v[i][j]].insert(mp(l,curr));
            }
        }
    string ans;
    int q,a,b,c;
    citeste(q);
    while(q--)
    {
        citeste(a);
        citeste(b);
        citeste(c);
        if(b<c)
            swap(b,c);
        if(available[a].empty())
        {
            ans+=not_existent;
            continue;
        }
        bool ok = 0;
        for(auto it:available[a])
        {
            if(it.f>=b && it.s>=c)
            {
                ok=1;
                ans+=can;
                break;
            }
        }
        if(!ok)
            ans+=cannot;
    }
    fout<<ans;
}
