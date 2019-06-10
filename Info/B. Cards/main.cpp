#include <iostream>

using namespace std;
int a,b,c,i,n;
char x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        if(x=='R')
        c++;
        else
        if(x=='G')
        b++;
        else
        a++;
    }
    if(a && b && c)
        cout<<"BGR";
    else
    if(!a)
    {
        if(!b)
            cout<<'R';
        else
        if(!c)
            cout<<'G';
        else
        if(b==1 && c==1)
        cout<<'B';
        else
        if(c==1 && b>=2)
        cout<<"BR";
        else
        if(c>=2 && b==1)
        cout<<"BG";
        else
        cout<<"BGR";
    }
    else
    if(!b)
    {
        if(!a)
            cout<<'R';
        else
        if(!c)
            cout<<'B';
        else
        if(a==1 && c==1)
        cout<<'G';
        else
        if(c==1 && a>=2)
        cout<<"GR";
        else
        if(c>=2 && a==1)
        cout<<"BG";
        else
        cout<<"BGR";
    }
    else
    if(!c)
    {
        if(!b)
            cout<<'B';
        else
        if(!a)
            cout<<'G';
        else
        if(b==1 && a==1)
        cout<<'R';
        else
        if(a==1 && b>=2)
        cout<<"BR";
        else
        if(a>=2 && b==1)
        cout<<"GR";
        else
        cout<<"BGR";
    }
}
