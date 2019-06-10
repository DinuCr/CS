#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("sr.in");
ofstream fout("sr.out");

char a[100100];
char b[100100];
int i;
int n;

int main()
{
    fin>>a>>b;
    n=strlen(a);
    int j=0;
    for(j=0; j<n; ++j)
    {
        if(a[j]==b[i])
        {
            fout<<j+1<<' ';
            ++i;
        }
    }
}
