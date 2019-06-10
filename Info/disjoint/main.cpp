#include <fstream>
using namespace std;
int n,m,t[100001];
int r(int n)
{
    while(t[n])
        n=t[n];
    return n;
}
ifstream f("disjoint.in");
ofstream g("disjoint.out");
int main()
{
    int p,a,b;
    f>>n>>m;
    while(m--)
    {
        f>>p>>a>>b;
        if(p==1)
            t[r(b)]=r(a);
        else if(r(a)==r(b))
            g<<"DA\n";
        else
            g<<"NU\n";
    }
    return 0;
}
