#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
ifstream f("codul1.in");
ofstream g("codul1.out");
int i,j,k,n,v[100];
char s[1000],x;
int main()
{
    f>>s;n=strlen(s);
    for(k=1;k<strlen(s);k++)
    for(i=0;i<='z'-'a';i++)
    {
        if(i%k==0)
            g<<s[i];

    }
    g.close();
}
