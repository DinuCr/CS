#include <iostream>
#include <stdio.h>
#include <cstring>
#include <cmath>
using namespace std;
char s[102000];
long i,k,n;
int dmax(char a[])
{
    int s=0;
    int n=strlen(a);
    for(int i=0;i<n;i++)
    s+=max(abs(a[i]-'a'),abs(a[i]-'z'));
    return s;
}
int main()
{
    scanf("%d %d %s",&n,&k,&s);
    if(dmax(s)<k)
        cout<<"-1";
    else
    {
        for(i=0;i<n;i++)
        {
            if(max(abs(s[i]-'a'),abs(s[i]-'z'))<=k)
            {
                if(abs(s[i]-'a')>abs(s[i]-'z'))
                    printf("a");
                else
                    printf("z");
                k-=max(abs(s[i]-'a'),abs(s[i]-'z'));
            }
            else
            if(k==0)
            printf("%c",s[i]);
            else
            {
                if('z'-s[i]>k)
                    printf("%c",s[i]+k);
                else
                    printf("%c",s[i]-k);
                k=0;
            }

        }
    }

}
