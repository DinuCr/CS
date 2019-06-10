#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("nc.in");
ofstream fout("nc.out");

char s[10000];
long long ans[1000000];
int k,i;

int main()
{
    k=0;
    while(!fin.eof())
    {
        fin.getline(s,4100);
        int n=strlen(s);
        for(i=0; i<n; ++i)
        {
            if((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A'))
            {
                if((s[i+1]>'z' || s[i+1]<'a') && (s[i+1]>'Z' || s[i+1]<'A'))
                    ans[k]++;
            }
            else
            if(s[i]=='!' || s[i]=='?' || (s[i]=='.' && s[i+1]!='.'))
            {
                ++k;
            }
        }
    }
    if(ans[k]!=0)
        ++k;
    fout<<k<<'\n';
    for(i=0; i<k; ++i)
        fout<<ans[i]<<'\n';
}
