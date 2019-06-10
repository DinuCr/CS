#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("pscpld.in");
ofstream fout("pscpld.out");

#define nmax 1000100

char a[nmax];
char s[nmax*2];
int d[nmax*2];
int n,i,j,l,r,c;

int main()
{
    fin>>a;
    n = strlen(a);

    for(i=0; i<n; ++i)
    {
        s[2*i]='!';
        s[2*i+1]=a[i];
    }
    s[2*n]='!';
    n = n*2 + 1;

    c=0;

    for(i=0; i<n; ++i)
    {
        if(i<=c+(d[c]>>1))
            d[i]=min(d[(c<<1)-i],((c-i+(d[c]>>1))<<1)+1);
        if(!d[i])
            d[i]=1;

        l=i-(d[i]>>1);
        r=i+(d[i]>>1);

        while(l>0 && r<n && s[r+1]==s[l-1])
        {
            --l;
            ++r;
            d[i]+=2;
        }
        if(i + (d[i]>>1) > c + (d[c]>>1))
            c=i;
    }

    long long ans = 0 ;
    for(i=0; i<n; ++i)
        if(s[i]=='!')
            ans+=d[i]/4;
        else
            ans+=(d[i]+1)/4;
    fout<<ans;
}
