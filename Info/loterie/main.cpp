#include<iostream>
#include<fstream>
using namespace std;
ifstream f("loterie.in");
ofstream g("loterie.out");
long long s,n,k;
long long comb(int n,int k)
{
    if(k==0 && n!=0)
        return 1;
    if(k==n)
        return 1;
    if(k<0)
        return 0;
    return comb(n-1,k)+comb(n-1,k-1);
}
int main()
{
    f>>n>>k;
    s=comb(n,k);
    g<<s;
    g.close();
}
