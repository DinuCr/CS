#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
ifstream f("reteta2.in");
ofstream g("reteta2.out");
typedef struct ingredient
{
    char s[22];
    int g;
};
ingredient v[102];
char c,a[22],ok,i,j;
int t,n,nr;
int main()
{
    f>>c;
    while(!f.eof())
    {
        if(c<='z' && c>='a')
        {
            nr=0;
            while(c<='z' && c>='a')
            {
                a[nr++]=c;
                f>>c;
            }
            a[nr]=NULL;
        }
        else
        if(c<='9' && c>='0')
        {
            nr=0;
            while(c<='9' && c>='0' && !f.eof())
            {
                nr=nr*10+c-'0';
                f>>c;
            }
            if(nr==0)
                nr=1;
            ok=1;
            for(i=1;i<=n;i++)
            if(strcmp(a,v[i].s)==0)
            {
                v[i].g+=nr;
                ok=0;
                break;
            }
            if(ok)
            {
                v[++n].g=nr;
                strcpy(v[n].s,a);
            }
        }
        else
        if(c==')')
        {
            f>>c;
            while(c==' ')
                f>>c;
            nr=0;
            while(c<='9' && c>='0' && !f.eof())
            {
                nr=nr*10+c-'0';
                f>>c;
            }
            t+=nr;
        }
        else
        f>>c;
    }
    g<<t<<'\n';
    for(i=1;i<n;i++)
    for(j=i+1;j<=n;j++)
    if(strcmp(v[i].s,v[j].s)>0)
    swap(v[i],v[j]);
    for(i=1;i<=n;i++)
        g<<v[i].s<<' '<<v[i].g<<'\n';
}
