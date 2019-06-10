#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char s1[1000100],s2[1000100];
int a,n,b,m,ok,i,j;
int main()
{
    scanf("%s%s",s1,s2);
    while(s1[a]=='0')
        a++;
    while(s2[b]=='0')
        b++;
    n=strlen(s1);
    m=strlen(s2);
    if(n-a>m-b)
        ok=-1;
    if(n-a<m-b)
        ok=1;
    if(ok==0)
    for(i=a,j=b;i<n;i++,j++)
    if(s1[i]<s2[j])
    {
        ok=1;
        break;
    }
    else
    if(s1[i]>s2[j])
    {
        ok=-1;
        break;
    }
    switch(ok)
    {
    case -1:
        cout<<'>';
        break;
    case 0:
        cout<<'=';
        break;
    case 1:
        cout<<'<';
        break;
    }
}
