#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
double x1,x2,a,b,c;
int main()
{
    cin>>a>>b>>c;
    setprecision(8);
    x1=-b+(setprecision(7))sqrt(b*b-4*a*c);
    x1=(double)x1/(2*a);
    x2=-b-((setprecision(7)))sqrt(b*b-4*a*c);
    x2=(double)x2/(2*a);
    cout<<max(x1,x2)<<'\n'<<min(x1,x2);
}
