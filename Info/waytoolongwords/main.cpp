#include<iostream>
#include<cstring>
using namespace std;
int i,n;
char s[101];
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>s;
        if(strlen(s)<11)
            cout<<s<<'\n';
        else
        cout<<s[0]<<strlen(s)-2<<s[strlen(s)-1]<<'\n';
    }
}
