#include<iostream>
using namespace std;
char c;
void caracter(char c)
{
    cin>>c;
    if(c!='*')
    caracter(c);
    cout<<c;
}
int main()
{
    caracter(c);
}
