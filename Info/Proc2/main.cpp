#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("proc2.in");
ofstream fout("proc2.out");

#define mp make_pair
#define f first
#define s second

priority_queue <pair<int,int> ,vector <pair<int,int> > , greater <pair<int,int> > > q;
priority_queue <int, vector <int>, greater <int> > h;

int main()
{
    int n,m;
    fin>>n>>m;
    int x = 1;
    while(m--)
    {
        int a,b;
        fin>>a>>b;
        while(!q.empty() && q.top().f<=a)
        {
            h.push(q.top().s);
            q.pop();
        }
        if(h.empty())
        {
            fout<<x<<'\n';
            q.push(mp(b+a,x));
            ++x;
        }
        else
        {
            fout<<h.top()<<'\n';
            q.push(mp(a+b,h.top()));
            h.pop();
        }
    }
}
