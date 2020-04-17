#include <fstream>
#include <iostream>
using namespace std;
unsigned long long x,y,n,i;
int main(int argc, const char * argv[]) {

    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    freopen("9-mihai.in","r",stdin);
    freopen("mihai.out","w",stdout);


    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x>>y;
        if(x%2||y%2)
            cout<<1<<'\n';
        else
            cout<<0<<'\n';
    }
    return 0;
}
