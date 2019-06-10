#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("patrate2.in");
ofstream fout("patrate2.out");

int v[1000100];
int n,i;

void multiply(int x)
{
    int t=0;
    for(int i=1; i<=v[0]; ++i)
    {
        t+=x*v[i];
        v[i]=t%10;
        t/=10;
    }
    while(t)
    {
        ++v[0];
        v[v[0]]=t%10;
        t/=10;
    }
}

int main()
{
    fin>>n;
    v[0]=v[1]=1;
    for(i=2; i<=n; ++i)
        multiply(i);
    n*=n;
    for(i=1; i<=n; ++i)
        multiply(2);
    for(i=v[0]; i>0; --i)
        fout<<v[i];
}
