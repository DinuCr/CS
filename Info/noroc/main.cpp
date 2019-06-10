#include <iomanip>
#include <fstream>

using namespace std;

ifstream fin("noroc.in");
ofstream fout("noroc.out");

double m,x;

int main()
{
    fin>>x>>m;
    if(x>m)
        x=m;
    fout<<setprecision(7)<<fixed<<(double)1-(double)x/m;
}
