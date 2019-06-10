#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("knumere.in");
ofstream fout("knumere.out");

deque <int> q;
int v[1000100];
int d[1000100];
int n,k,i;

int main()
{
    fin>>n>>k;
    fin>>v[1];
    for(i=2; i<=n; ++i)
    {
        fin>>v[i];
        d[i]=v[i]-v[i-1];
    }
    long long mn = 2100000000000;
    int l=n-k-1;
    for(i=2; i<=n; ++i)
    {
        while(q.size() && d[q.back()]<=d[i])
            q.pop_back();
        if(q.size() && q.front()<=i-l)
            q.pop_front();
        q.push_back(i);
        if(i>l)
            mn=min(mn,d[q.front()]*1LL);
    }
    fout<<mn;
}
