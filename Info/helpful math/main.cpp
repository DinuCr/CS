#include<iostream>
#include<cstring>
using namespace std;
int v[4],i,nr;
char s[100];
int main()
{
    cin>>s;
    for(i=0;i<strlen(s);i++)
    if(s[i]<'4' && s[i]>'0')
    v[s[i]-'0']++;
    nr=v[1]+v[2]+v[3];
    i=1;
    while(i<=3)
    {
        while(v[i]==0)
            i++;
        if(nr==1)
            break;
        else
        {
            cout<<i<<'+';
            nr--;
            v[i]--;
        }
    }
    cout<<i;
}
