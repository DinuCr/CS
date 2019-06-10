#include <iostream>
#include <cstring>
using namespace std;
char c[35],s[100100];
int n,m,i,nr;
bool cautare(int p)
{
    for(int j=p,i=0;i<m;j++,i++)
    if(s[j]!=c[i])
    return 0;

    return 1;
}

int main()
{
    cin.getline(s,100100);
    cin.getline(c,35);
    n=strlen(s);
    m=strlen(c);
    n-=m;
    for(i=0;i<=n;i++)
    if(cautare(i))
    {
        nr++;
        i+=m-1;
    }
    cout<<nr;
}
