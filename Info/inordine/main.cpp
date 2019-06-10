#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inordine.in");
ofstream fout("inordine.out");

#define nmax 1010

int n;
int st[nmax];
int dr[nmax];
int v[nmax];
int rad[nmax];

void df(int x)
{
    if(st[x])
        df(st[x]);
    fout<<v[x]<<' ';
    if(dr[x])
        df(dr[x]);
}

int main()
{
    fin>>n;
    int i;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i]>>st[i]>>dr[i];
        rad[st[i]]=rad[dr[i]]=1;
    }
    for(i=1; i<=n; ++i)
        if(!rad[i])
            df(i);
}
