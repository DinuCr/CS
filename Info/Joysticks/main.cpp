#include <iostream>

using namespace std;
int a,b,nr;
int main()
{
    cin>>a>>b;
    while((a>=2 || b>=2) && (a>0 && b>0))
    {
        if(a<b)
        {
            b-=2;
            a++;
        }
        else
        {
            a-=2;
            b++;
        }
        nr++;
    }
    cout<<nr;
}
