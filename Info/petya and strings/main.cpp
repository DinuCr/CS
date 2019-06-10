#include<iostream>
#include<cstring>
using namespace std;
int ok,i;
char a[101],b[101];
int ordine(char x)
{
    if(x<='Z')
        return x-'A';
    return x-'a';
}
int main()
{
    cin>>a>>b;
    ok=0;
    for(i=0;i<strlen(a);i++)
    {
        if(ordine(a[i])<ordine(b[i]))
        {
            ok=-1;
            break;
        }
        else
        if(ordine(a[i])>ordine(b[i]))
        {
            ok=1;
            break;
        }
    }
    cout<<ok;
}
