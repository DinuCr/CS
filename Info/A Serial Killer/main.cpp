#include <iostream>
#include <cstring>

using namespace std;

char a[15],b[15];
char x[15],y[15];
int n;

int main()
{
    cin>>a>>b>>n;
    for(int i=1; i<=n; ++i)
    {
        cout<<a<<' '<<b<<'\n';
        cin>>x>>y;
        if(strcmp(a,x)==0)
            strcpy(a,y);
        else
            strcpy(b,y);
    }
    cout<<a<<' '<<b;
}
