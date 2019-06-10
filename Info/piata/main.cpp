#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector <int> v;
inline int suma(int x)
{
    int s=0;
    while(x>0)
    {
        s+=x%10;
        x/=10;
    }
    return s;
}
ifstream f("piata.in");
ofstream g("piata.out");
int x1,x2,s1,s2,y1,y2,n1,n2,i,d,n,s;
int main()
{
    f>>n;
    f>>x1>>y1>>x2>>y2;
    int ok;
    if((x2<=y1 && x1<=y2) || (x2>y1 && x1>y2))
        ok=0;
    else
        ok=1;
    s1=((x2-1)*(n-1)%n+y1)%n;
    s2=((x1-1)*(n-1)%n+y2)%n+n*ok;
    v.push_back(0);
    for(i=s1;i<=s2;i++)
    if(i<=n)
    v.push_back(suma(i)+v.back());
    else
    v.push_back(suma(i-n)+v.back());
    d=y2-y1;
    s=0;
    vector <int>::iterator a,b;
    for(a=v.begin()+d+1,b=v.begin(); a<v.end(); a++,b++)
        s+=*a-*b;
    g<<s;
}
