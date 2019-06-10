#include <iostream>
#include <stdio.h>
#include <cstring>
using namespace std;
char s[310000];
long long n,i,mx,nr;
int main()
{
    scanf("%s",&s);
    n=strlen(s);
    for(i=1;i<n;i++)
    {
        nr=(s[i-1]-'0')*10+s[i]-'0';
        if(nr%4==0)
            mx+=i;
    }
    for(i=0;i<n;i++)
        if((s[i]-'0')%4==0)
        mx++;
    printf("%I64d",mx);
}
