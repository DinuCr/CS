#include <fstream>

using namespace std;

ifstream fin("suma2.in");
ofstream fout("suma2.out");

int main()
{
    int n;
    fin>>n;
    int last = -1e9;
    int mx = 0;
    for(int i=1; i<=n; ++i)
    {
        int x;
        fin>>x;
        int aux = last;
        last = max(x,mx+x);
        mx=max(mx,aux);
    }
    fout<<max(mx,last);
}
