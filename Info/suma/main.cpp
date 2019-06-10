#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("suma.in");
ofstream fout("suma.out");

int n,p;

int main()
{
    fin>>n>>p;
    if(n%3==0)
    {
        fout<<1LL*(n/3)*(n-1)%p*(n+1)%p;
    }
    else
    if((n-1)%3==0)
    {

        fout<<1LL*((n-1)/3)*(n)%p*(n+1)%p;
    }
    else
        fout<<1LL*((n+1)/3)*(n-1)%p*(n)%p;
}
