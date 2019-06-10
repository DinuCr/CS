#include <iostream>
#include <cstring>
using namespace std;
char s[300],c[50];
int ok,j,n,m,i;
int main()
{
    cin.getline(s,300);
    ok=0;
    cin.getline(c,50);
    j=0;
    n=strlen(s);
    m=strlen(c);
    for(i=0;i<n;i++)
    {
        if(j==m)
        {
            ok=1;
            for(j=i-m;j<i;j++)
                s[j]='*';
            j=0;
        }
        else
        if(s[i]==c[j])
            j++;
        else
            j=0;
    }
    if(j==m)
        {
            ok=1;
            for(j=i-m;j<i;j++)
                s[j]='*';
        }
    if(ok)
        cout<<s;
    else
        cout<<"NU APARE";
}
