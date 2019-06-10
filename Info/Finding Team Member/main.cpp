#include <iostream>
#include<fstream>
using namespace std;
ifstream f("team.in");
int v[400],w[400],i,j,a,n;
int main()
{
    f>>n;
    for(i=2;i<=2*n;i++)
    for(j=1;j<i;j++)
    {
        f>>a;
        if(a>v[j])
        {
            v[j]=a;
            v[i]=a;
            w[i]=j;
            w[j]=i;
        }
    }
    for(i=1;i<=2*n;i++)
        cout<<w[i]<<' ';
}
