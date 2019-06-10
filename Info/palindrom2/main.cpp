#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("palindrom2.in");
ofstream fout("palindrom2.out");

char s[3000];
int i,n,j;

bool verif(int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        if(s[i]!=s[j])
            return 0;
        ++i,--j;
    }
    return 1;
}

int main()
{
    fin>>s;
    n = strlen(s);
    int i=0;
    while(!verif(n+i))
    {
        for(int j=i; j>=0; --j)
            s[n+j]=s[i-j];
        ++i;
    }
    fout<<s;
}
