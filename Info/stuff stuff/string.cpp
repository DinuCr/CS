#include<iostream>
#include<string>
#include<fstream>
using namespace std;
ifstream f("string.in");
char v[100],x;
int i;
int main()
{
    f>>x;
    while(x!=' ')
    {
        i++;
        v[i]=x;
        f>>x;
    }
    while(i)
    {
        cout<<v[i];
        i--;
    }
    cout<<'\n';
    i=0;
    f>>x;
    while(x!=0)
    {
        i++;
        v[i]=x;
        f>>x;
    }
    while(i)
    {
        cout<<v[i];
        i--;
    }
    cout<<'\n';
    i=0;
    f.close();
    return 0;
}
