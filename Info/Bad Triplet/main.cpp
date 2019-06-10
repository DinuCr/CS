#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define nmax (int)1e5+10

vector <int> v[nmax];
vector <int> inc[nmax];

int ok,a,b,n,i,nr,m,ans;
int viz[nmax];
int t[nmax];

void df(int x)
{
    if(ok)
        return;
    for(auto it:v[x])
    {
        if(ok)
        return;
        if(it==t[x])
            continue;
        if(!viz[it])
        {
            viz[it]=viz[x]+1;
            inc[viz[it]].push_back(it);
            if(inc[viz[it]].size()==3)
                ans = viz[it];
            t[it]=x;
            df(it);
        }
        else
        if((int)(abs(viz[it]-viz[x])+1)%3==0)
        {
            ok=1;
            a = x;
            nr = (abs(viz[it]-viz[x])+1)/3;
            break;
        }
    }
}

void compute_answer(int a,int nr)
{
    cout<<a<<' ';
    int x = nr;
    while(x)
        a=t[a],x--;
    cout<<a<<' ';
    x = nr;
    while(x)
        a=t[a],x--;
    cout<<a<<' ';
}

int main()
{
    cin>>n>>m;
    for(i=1; i<=m; ++i)

    {
        cin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    viz[1]=1;
    df(1);
    if(!ok)
    {
        if(ans!=0)
            for(i=0; i<3; ++i)
                cout<<inc[ans][i]<<' ';
        else
        cout<<-1;
    }
    else
    {
        compute_answer(a,nr);
    }
}
