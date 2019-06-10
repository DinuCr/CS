#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define nmax 1300000

int v[nmax];
int mx[nmax];
int mn[nmax];
deque <int> q;
int n,i,z;

int main()
{
    fin>>n;
    n*=2;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=n+1; i<=n*2; ++i)
        v[i]=v[i-n];
    for(i=n*2+1; i<=3*n; ++i)
        v[i]=v[i-n];
    n/=2;
    for(i=n*6; i>0; --i)
    {
        while(q.size() && v[q.back()]<v[i])
            q.pop_back();
        q.push_back(i);
        mx[i]=q.front();
        while(q.size() && q.front()-i>=n-1)
            q.pop_front();
    }
    while(q.size())
        q.pop_front();
    for(i=n*6; i>0; --i)
    {
        while(q.size() && v[q.back()]>v[i])
            q.pop_back();
        q.push_back(i);
        mn[i]=q.front();
        while(q.size() && q.front()-i>=n-1)
            q.pop_front();
    }
    fin>>z;
    int p1=1;
    int p2=n+1;
    int x;
    while(z--)
    {
        fin>>x;
        p1-=x;
        if(p1<=0)
            p1=p1+n*2;
        p2=n+p1;
        fout<<v[mn[p1]]<<' '<<v[mx[p2]]<<'\n';
    }
}
