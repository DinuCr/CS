#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("cifra.in");
ofstream fout("cifra.out");

char s[1000];
int k,i,j,ok,t,n;

int main()
{
    int vp[11],vi[11];
    vi[1]=1;vi[2]=4;vi[3]=7;vi[4]=6;vi[5]=5;vi[6]=6;vi[7]=3;vi[8]=6;vi[9]=9;
    vp[1]=1;vp[2]=6;vp[3]=3;vp[4]=6;vp[5]=5;vp[6]=6;vp[7]=7;vp[8]=4;vp[9]=9;
    fin>>t;
    for(k=1; k<=t; ++k)
    {
        fin>>s;
        ok=0;
        n=strlen(s);
        if(n>1)
            ok=((s[n-2]-'0')*7)%10;
        if(n==1 || (s[n-2]-'0')%2==0)
            for(i=1; i<=s[n-1]-'0'; ++i)
                ok+=vi[i];
        else
            for(i=1; i<=s[n-1]-'0'; ++i)
                ok+=vp[i];
        ok%=10;
        fout<<ok<<'\n';
    }
}
