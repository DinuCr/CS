#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <unordered_map>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define ll long long

unordered_map <long long,bool> h;

struct sir
{
    char s[12];
    ll id;
    int last;
};

sir v[100100];
int n,i,j;

bool cmp(sir a,sir b)
{
    return a.last>b.last;
}


int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i].s;
        int x = strlen(v[i].s);
        ll p = 1;
        v[i].last = i;
        for(j=x-1; j>=0; --j)
            v[i].id = v[i].id + (v[i].s[j]-'a'+1)*p,p*=27;
    }

    sort(v+1,v+n+1,cmp);
    fout<<v[1].s<<'\n';
    h[v[1].id]=1;
    for(i=2; i<=n; ++i)
        if(h[v[i].id]==0)
        {
            h[v[i].id]=1;
            fout<<v[i].s<<'\n';
        }
}
