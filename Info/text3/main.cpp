#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("text3.in");
ofstream fout("text3.out");

struct desc
{
    char l,r;
};

struct word
{
    char s[25];
    int l;
};

word v[20100];
desc w[20100];
int last[30];
int d[20100];
int ans[20100];
int n,mx,poz;

int main()
{
    int i = 1;
    while(fin>>v[i].s)
        {
            v[i].l=strlen(v[i].s);
            w[i].l=v[i].s[0];
            w[i].r=v[i].s[v[i].l-1];
            ++i;
        }
    n=i-1;
    fout<<n<<'\n';
    for(i=1; i<=n; ++i)
    {
        d[i]=d[last[w[i].l-'a']]+1;
        if(d[i]>d[last[w[i].r-'a']])
            last[w[i].r-'a']=i;
        if(d[i]>mx)
        {
            mx=d[i];
            poz=i;
        }
    }
    fout<<n-mx<<'\n';
    int k=0;
    ans[k++]=poz;
    for(i=poz-1; i>0; --i)
    if(d[i]==d[poz]-1 && w[i].r==w[poz].l)
    {
        ans[k++]=i;
        poz=i;
    }
    for(i=k-1; i>=0; --i)
        fout<<v[ans[i]].s<<'\n';
}
