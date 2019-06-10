#include <iostream>
#include<cstring>
using namespace std;
int i;
char s[101];
int main()
{
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(s[i]<='Z' && s[i]>='A')
            s[i]+=32;
        if(s[i]!='a' && s[i]!='e' && s[i]!='i' && s[i]!='o' && s[i]!='u' && s[i]!='y')
            cout<<'.'<<s[i];
    }
}
