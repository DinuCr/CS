#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define f first
#define s second

vector <pair < int, pair< int,int > > > w;
char v[60][60];
int d[60][60];
int nr,ok,n,m,i,j,k,a;

bool compare(pair<int, pair<int,int> > a, pair<int, pair<int,int > > b)
{
    return a.f>b.f;
}

void f(int i,int j)
{
    if(v[i][j])
    {
        if(v[i][j]=='.' && d[i][j]==0 && (i==1 || i==n || j==m || j==1))
        {
            ok=0;
            d[i][j]=1;

            f(i+1,j);
            f(i,j+1);
            f(i-1,j);
            f(i,j-1);

        }
        else if(!d[i][j] && v[i][j]=='.')
        {
            d[i][j]=1;
            ++nr;
            f(i+1,j);
            f(i,j+1);
            f(i-1,j);
            f(i,j-1);
        }
    }
}

void f1(int i,int j)
{
    if(v[i][j]=='.')
    {
        v[i][j]='*';
        f1(i+1,j);
        f1(i,j+1);
        f1(i-1,j);
        f1(i,j-1);
    }
}


int main()
{
    cin>>n>>m>>k;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            cin>>v[i][j];
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
            if(d[i][j]==0 && v[i][j]=='.')
            {
                ok=1;
                nr=0;
                f(i,j);
                if(ok)
                {
                    ++a;
                    w.push_back(make_pair(nr,make_pair(i,j)));
                }
            }
    nr=0;
    sort(w.begin(),w.end(),compare);
    while(a>k)
    {
        nr+=w.back().f;
        --a;
        f1(w.back().s.f,w.back().s.s);
        w.pop_back();
    }
    cout<<nr<<'\n';
    for(i=1; i<=n; ++i)
    {
        for(j=1; j<=m; ++j)
            cout<<v[i][j];
        cout<<'\n';
    }
}
