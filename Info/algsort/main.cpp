#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    ifstream f("algsort.in");
    ofstream g("algsort.out");
    int i,n,v[500100];
    f>>n;
    for(i=0; i<n; ++i)
        f>>v[i];
    sort(v,v+n);
    for(i=0; i<n; ++i)
        g<<v[i]<<' ';
}
