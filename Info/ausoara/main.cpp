#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("ausoara.in");
ofstream fout("ausoara.out");

int a[1010];
int b[1010];

int main()
{
    int n,m,i,j,n2;
    fin>>m;
    fin>>n2;
    for(i=1; i<=n2; ++i)
        fin>>a[i];
    while((m--)>1)
    {
        fin>>n;
        for(i=1; i<=n; ++i)
            fin>>b[i];
        vector <int> curr;
        i=1;
        j=1;
        while(i<=n2 && j<=n)
            if(a[i]==b[j])
            {
                curr.push_back(a[i]);
                ++i,++j;
            }
            else
            if(a[i]<b[j])
                ++i;
            else
                ++j;
        n2=0;
        for(auto it:curr)
            a[++n2]=it;
    }
    fout<<n2<<' ';
    for(i=1; i<=n2; ++i)
        fout<<a[i]<<' ';
}
