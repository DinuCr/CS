#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("kbiti.in");
ofstream fout("kbiti.out");

char s[50];
long long nr;
int n,q,i;


int main()
{
    fin>>q;
    while(q--)
    {
        fin>>s;
        n=strlen(s);
        nr=0;
        for(i=n-1; i>=0; --i)
            if(s[i]-'0')
                nr+=(long long)1<<(n-i-1);
        fout<<nr+1<<'\n';
    }
}
