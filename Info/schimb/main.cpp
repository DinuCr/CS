#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("schimb.in");
ofstream fout("schimb.out");

char s[550];
int i,n,p,k,l;

int main()
{
    fin>>n>>k>>p;
    fin.getline(s,50);
    while(n--)
    {
        fin.getline(s,505);
        l = strlen(s);
        if(k>l)
        {
            for(i=l-1; i>=0; --i)
                fout<<s[i];
            fout<<'\n';
        }
        else
        {
            s[k-1]='a'+p-1;
            for(i=0; i<l; ++i)
                fout<<s[i];
            fout<<'\n';
        }
    }
}
