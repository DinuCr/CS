#include <iostream>

using namespace std;
char a[10],b[10];
int ok,i,j,k;
int main()
{
    for(i=1;i<=4;i++)
    cin>>a[i];
    swap(a[3],a[4]);
    for(i=1;i<4;i++)
        if(a[i]=='X')
            for(j=i;j<4;j++)
            a[j]=a[j+1];
    for(i=1;i<=4;i++)
    cin>>b[i];
    swap(b[3],b[4]);
    for(i=1;i<4;i++)
        if(b[i]=='X')
            for(j=i;j<4;j++)
            b[j]=b[j+1];



    for(i=4;i<=8;i++)
    {
        a[i]=a[i-3];
        b[i]=b[i-3];
    }
    for(k=1;k<=3;k++)
    {
        ok=1;
        for(j=k,i=1;j<k+3;j++,i++)
            if(a[i]!=b[j] && a[i]!='X' && b[j]!='X')
            {
                ok=0;
                break;
            }
            else
            {
            if(a[i]=='X')
                j--;
            else
            if(b[j]=='X')
                i--;
            }
        if(ok)
        {
            cout<<"YES";
            break;
        }
    }
    if(!ok)
        cout<<"NO";
}
