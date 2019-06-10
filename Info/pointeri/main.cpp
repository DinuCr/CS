#include <iostream>
#include<cstdlib>
using namespace std;
int *a[100],i;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        a[i]realloc(a,i*sizeof(int));
        *a[i]=i;
    }
    for(i=1;i<=n;i++)
    cout<<*a[i]<<' ';
}
