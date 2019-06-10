#include<iostream>
using namespace std;
int v[6],i,n;
int main()
{
    cin>>n;
    v[1]=1;
    v[2]=1;
    v[3]=1;
    v[4]=1;
    v[5]=1;
    i=1;
    while(n>0)
    {
        n-=v[i];
        v[i]*=2;
        if(n<=0)
        switch(i)
        {
        case 1:
            {
                cout<<"Sheldon";
                break;
            }
        case 2:
            {
                cout<<"Leonard";
                break;
            }
        case 3:
            {
                cout<<"Penny";
                break;
            }
        case 4:
            {
                cout<<"Rajesh";
                break;
            }
        case 5:
            {
                cout<<"Howard";
                break;
            }
        }
        i=(i<5)?i+1:1;
    }
}
