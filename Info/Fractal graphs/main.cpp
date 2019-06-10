#include <iostream>
#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

inline void mod(long long &x)
{
    if(x>=32749)
        x = x%32749;
}

int main()
{
    int n;
    fin>>n;
    long long v = 1;
    long long e = 0;
    long long v2,e2;
    int i = 0,c=0;
    for(i=0; i+3<=n; i+=3)
    {
        v2=81*v+66*e;
        e2=99*v+81*e;
        v = v2;
        e = e2;
        ++c;
        if(c==6)
        {
            c=0;
            mod(v);
            mod(e);
        }
    }
    if(i<n)
    {
        v2=((v+e)<<1)+v;
        e2=v2+e;
        v = v2;
        e = e2;
        mod(v);
        mod(e);
        ++i;
    }
    if(i<n)
    {
        v2=((v+e)<<1)+v;
        e2=v2+e;
        v = v2;
        e = e2;
        mod(v);
        mod(e);
        ++i;
    }
    mod(v);
    mod(e);
    fout<<v<<' '<<e;
}
