#include<iostream>
#include<cstring>
using namespace std;
int a1,b1,nr,a2,b2,i,ok;
char s[100001];
int main()
{
    cin>>s;
    while(i<strlen(s))
    {
        ok=true;
        if(s[i]=='A' && s[i+1]=='B')
        {
            i+=2;nr=2;ok=false;
            while(s[i]!=s[i-1] && (s[i]=='A' || s[i]=='B'))
            {
                i++;
                nr++;
            }
            if(nr>a1)
            {
                a2=a1;
                a1=nr;
            }
            else
            if(nr>a2)
            a2=nr;
        }
        else
        if(s[i]=='B' && s[i+1]=='A')
        {
            i+=2;nr=2;ok=false;
            while(s[i]!=s[i-1] && (s[i]=='A' || s[i]=='B'))
            {
                i++;
                nr++;
            }
            if(nr>b1)
            {
                b2=b1;
                b1=nr;
            }
            else
            if(nr>b2)
            b2=nr;
        }
        i+=ok;
    }
    if((a1!=0 && b1!=0) || a1>4 || b1>4 || (a1>2 && a2>1) ||(b1>2 && b2>1))
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}
