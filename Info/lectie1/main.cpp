#include<iostream>
using namespace std;
int main()
{
    int n,p,i,nr1,nr2;
    nr1=-1;nr2=-1;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>p;
        if(p%2==1)
        {
            nr1=nr2;
            nr2=p;

        }
    }
    if(nr1==-1)
    cout<<"Numere insuficiente";
    else
    cout<<nr1<<' '<<nr2;
    return 0;
}
