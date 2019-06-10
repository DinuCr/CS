#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("treap.in");
ofstream fout("treap.out");

#define nmax 150010

vector <int> v[nmax];
int chei[nmax];
int pr[nmax];
int maxch[nmax];
int minch[nmax];
int maxp[nmax];
int ok[nmax];

void df(int x,int t)
{
    int a=0,b=0;
    for(auto it:v[x])
        if(it!=t)
        {
            df(it,x);
            if(!a)
                a=it;
            else
                b=it;
        }
    if(a==0)
    {
        ok[x]=1;
        minch[x]=chei[x];
        maxch[x]=chei[x];
        maxp[x]=pr[x];
    }
    else
    if(b==0)
    {
        if(ok[a])
        {
            if( (maxch[a]<=chei[x] || minch[a]>chei[x]) && maxp[a]<=pr[x])
            {
                ok[x]=1;
                maxch[x]=max(maxch[a],chei[x]);
                minch[x]=min(minch[a],chei[x]);
                maxp[x]=pr[x];
            }
            else
                ok[x]=0;
        }
        else
        ok[x]=0;
    }
    else
    {
        if(ok[a] && ok[b])
        {
            if ( ( (maxch[a]<=chei[x] && minch[b]>chei[x]) || (maxch[b]<=chei[x] && minch[a]>chei[x]) )
                && maxp[a]<=pr[x] && maxp[b]<=pr[x])
            {
                ok[x]=1;
                maxp[x]=pr[x];
                minch[x]=min(chei[x],min(minch[a],minch[b]));
                maxch[x]=max(chei[x],max(maxch[a],maxch[b]));
            }
            else
            ok[x]=0;
        }
        else
        ok[x]=0;
    }
}
int main()
{
    int n,i,a,b;
    fin>>n;
    for(i=1; i<n; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for(i=1; i<=n; ++i)
        fin>>chei[i];
    for(i=1; i<=n; ++i)
        fin>>pr[i];
    df(1,0);
    for(i=1; i<=n; ++i)
        fout<<ok[i]<<' ';
    fout<<'\n';
}
