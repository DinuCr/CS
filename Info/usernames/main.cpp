#include <iostream>
#include <fstream>
#include <vector>
#include <cstring>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

#define nmax 10100

long long v[nmax];
int n,i,j,ans;
char s[100];
long long curr;
long long p[45];

int main()
{
    fin>>n;
    p[0]=1;
    for(i=1; i<=43; ++i)
        p[i]=p[i-1]*2;
    for(i=1; i<=n; ++i)
    {
        fin>>s;
        curr=0;
        int l = strlen(s);
        for(int j = 0; j<l; ++j)
            if(s[j]<='z' && s[j]>='a')
                curr=curr | p[s[j]-'a'];
            else
                curr=curr | p[s[j]-'0'+30];
        v[i]=curr;
    }
    for(i=1; i<=n; ++i)
        for(j=i+1; j<=n; ++j)
        {
            if((v[i]&v[j])==v[i])
                ++ans;
            if((v[i]&v[j])==v[j])
                ++ans;
        }
    fout<<ans;
}
