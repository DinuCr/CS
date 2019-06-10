#include <iostream>
#include <fstream>
using namespace std;
int n,k;
ifstream f("pscarb.in");
ofstream g("pscarb.out");
int main()
{
    f>>n>>k;
    if(n%2&&k==2)
    {
        for(int i=1;i<n;i++)
            g<<i<<" "<<i+1<<'\n';
        g<<'R';
        for(int i=2;i<n;i++)
            g<<'B';
        g<<'G';
        return 0;
    }
    g<<-1;
    return 0;
}
