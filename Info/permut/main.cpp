#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("permut.in");
ofstream fout("permut.out");

int v[100100];
int w[100100];

int n,i;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    for(i=1; i<=n; ++i)
        fin>>w[i];
    sort(v+1,v+n+1);
    sort(w+1,w+n+1);
    long long s = 0;
    for(i=1; i<=n; ++i)
        s+=1LL*v[i]*w[i];
    fout<<s;
}
