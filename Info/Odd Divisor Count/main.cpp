#include <iostream>
#include <cmath>

using namespace std;

int a,b,nr;

int main()
{
    cin>>a>>b;
    nr=0;
    for(int i=a; i<=b; ++i)
    {
        if(i==(int)sqrt(i)*(int)sqrt(i) && i%(int)sqrt(i)==0)
            ++nr;
    }
    cout<<nr;
}
