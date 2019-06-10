#include <iostream>
using namespace std;
long long x1,x2,y1,y2,r,x,nr;
int main()
{
    cin>>x1>>y1>>x2>>y2;
    r=x2-x1+1;
    x=y2-y1+1;
    if(x%2==0)nr=r*(x/2);
    else{
        if(r%2==1){nr=(r/2+1)*(x/2+1)+(r/2)*(x/2);}
        else {nr=(r/2)*(x+1);}
    }
    cout<<nr;
    return 0;
}
