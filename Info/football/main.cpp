#include<iostream>
#include<cstring>
using namespace std;
int i,ok,nr;
char s[102];
int main()
{
    cin>>s;nr=1;
    for(i=1;i<strlen(s);i++)
    {
        if(s[i]==s[i-1])
            nr++;
        else
            nr=1;
        if(nr>6)
        {
            ok=true;
            break;
        }
    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
