#include <algorithm>
#include <fstream>
#include <iostream>
using namespace std;

ifstream fin("1-sir.in");
ofstream fout("1-sir.out");
const int p=194767;

int n,s,i,j,d[260][35500];

int main()
{
    fin>>n>>s;
    s=abs(s);
    if(abs(s)>n*(n-1)/2)
        fout<<0;
    else
    {
        d[1][0]=1;
        for(i=2; i<=n; ++i)
            for(j=0; j<=i*(i-1)/2; ++j)
                d[i][j]=(d[i-1][j+i-1]+d[i-1][abs(j-i+1)])%p;
        fout<<d[n][s];
    }
}
