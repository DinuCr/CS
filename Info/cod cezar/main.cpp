#include<iostream>
#include<cstring>
using namespace std;
int i;
char s[100];
int main()
{
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        s[i]=s[i]-10;
        if(s[i]<'a')
            s[i]='z'+s[i]-'a'+1;
    }
    cout<<s;
}
