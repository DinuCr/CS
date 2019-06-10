#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("inter.in");
ofstream fout("inter.out");

#define nmax 1010

int v[nmax];
int poz[nmax];

int main()
{
    int n,m,i;
    fin>>n>>m;
    int a,b;
    while(m--)
    {
        fin>>a>>b;
        if(a>b)
            swap(a,b);
        ++poz[a];
        --poz[b];
    }
    for(i=1; i<=n; ++i)
        v[i+poz[i]]=i;
    for(i=1; i<=n; ++i)
        fout<<v[i]<<' ';
}
