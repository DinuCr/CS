#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
int i,e[30],n;
char s[20100];
typedef struct part
{
    int v[30];
    part()
    {
        for(int i=0; i<30; ++i)
            v[i]=0;
    }
};
part x;
part rec(int ok)
{
    part a;
    int ok1=1;
    while(s[i]!=')' && i<n)
    {
        if(s[i]!='(')
        {
            if(s[i]<='z' && s[i]>='a')
                a.v[s[i]-'a']+=ok1*ok,e[s[i]-'a']=1;
            else if(s[i]=='*')
                ok1=1;
            else if(s[i]=='/')
                ok1=-1;
            i++;
        }
        else
        {
            i++;
            part b=rec(ok*ok1);
            for(int j=0; j<30; j++)
                a.v[j]+=b.v[j];
        }
    }
    i++;
    return a;
}
ifstream f("expresie3.in");
ofstream g("expresie3.out");
int main()
{
    f.getline(s,20100);
    n=strlen(s);
    x=rec(1);
    for(i=0;i<30;i++)
    if(e[i])
    {
        char c='a'+i;
        g<<c<<' '<<x.v[i]<<'\n';
    }
}
