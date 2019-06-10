#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("multimi2.in");
ofstream fout("multimi2.out");

int main()
{
    int n,i,ok;
    fin>>n;
    switch(n%4)
    {
    case 0:
        fout<<"0\n";
        fout<<n/2<<'\n';
        for(i=1,ok=1; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        fout<<'\n';
        fout<<n/2<<'\n';
        for(i=2,ok=0; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        break;
    case 1:
        fout<<"1\n";
        fout<<n/2+1<<'\n'<<"1 ";
        for(i=2,ok=1; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        fout<<'\n';
        fout<<n/2<<'\n';
        for(i=3,ok=0; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        break;
    case 2:
        fout<<"1\n";
        fout<<n/2<<'\n';
        for(i=1,ok=1; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        fout<<'\n';
        fout<<n/2<<'\n';
        for(i=2,ok=0; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        break;
    case 3:
        fout<<"0\n";
        fout<<n/2+1<<'\n';
        fout<<"1 2 ";
        for(i=4,ok=1; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        fout<<'\n';
        fout<<n/2<<'\n';
        fout<<"3 ";
        for(i=5,ok=0; i<=n; i+=ok*2+1,ok=!ok)
            fout<<i<<' ';
        break;
    }
}
