#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("text.in");
ofstream fout("text.out");

char c;
long long n,i;

int main()
{
    long long suma=0;
    long long nr=0;
    int ok=0;
    while(fin.get(c))
    {
        if((c>='a' && c<='z') || (c>='A' && c<='Z'))
        {
            ++suma;
            ok=1;
        }
        else
        {
            if(ok)
            {
                nr++;
                ok=0;
            }
        }
    }
    if(nr)
        fout<<suma/nr;
    else
        fout<<0;
}
