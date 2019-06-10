#include <iostream>
#include<cstring>
using namespace std;
int i,ok;
char s[102];
int main()
{
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]=='Q' || s[i]=='H' || s[i]=='9')
            ok=true;
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
}
