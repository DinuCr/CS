#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

ifstream fin("nrtri.in");
ofstream fout("nrtri.out");

int v[1000],n,i,nr,j;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    sort(v+1,v+n+1);
    for(i=1; i<n-1; ++i)
        for(j=i+1; j<n; ++j)
        {
            int *x = upper_bound(v+1,v+n+1,v[i]+v[j]);
            if(x-v-1>j)
                nr+=upper_bound(v+1,v+n+1,v[i]+v[j])-v-j-1;
        }
    fout<<nr;
}
