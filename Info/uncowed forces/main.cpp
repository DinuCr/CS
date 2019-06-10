#include <iostream>
using namespace std;
int v[5]={500,1000,1500,2000,2500},s,x[5],w[5],i;
int main()
{
    for(i=0;i<5;i++)
        cin>>x[i];
    for(i=0;i<5;i++)
        cin>>w[i];
    for(i=0;i<5;i++)
    {
        s+=max(3*v[i]/10,v[i]-v[i]*x[i]/250-50*w[i]);
    }
    cin>>i;
    s+=i*100;
    cin>>i;
    s-=i*50;
    cout<<s;
}
