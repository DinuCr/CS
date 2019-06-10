#include <fstream>
using namespace std;
ifstream f("euclid2.in");
ofstream g("euclid2.out");
int i,n,a,b;
int gcd (int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    f>>n;
    for(i=1;i<=n;i++)
    {
        f>>a>>b;
        g<<gcd(a,b)<<'\n';
    }
}
