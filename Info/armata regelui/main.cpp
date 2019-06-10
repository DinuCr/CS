#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream f("ar.in");
ofstream g("ar.out");

char r[5005],s[5005],c1,c2;

int v[30][30],n,m,i,k,n2,ok;
int a[30],b[30];

int main()
{
    f>>r;
    f>>n>>m;

    for(i=1; i<=n; ++i)
    {
        f>>c1>>c2;
        v[c1-'a'][c2-'a']=v[c2-'a'][c1-'a']=1;
    }

    n=strlen(r);
    for(i=0; i<n; ++i)
        ++a[r[i]-'a'];

    for(k=1; k<=m; ++k)
    {
        f>>s;
        n2=strlen(s);
        if(n2!=n)
            continue;

        for(i=0; i<26; ++i)
            b[i]=0;
        for(i=0; i<n2; ++i)
            ++b[s[i]-'a'];
        ok=1;
        for(i=0; i<26; ++i)
            if(a[i]!=b[i])
                ok=0;
        if(!ok)
            continue;

        ok=1;
        for(i=0; i<n; ++i)
        {
            if(s[i]==r[i])
                {
                    --b[s[i]-'a'];
                    continue;
                }
            if(v[r[i]-'a'][s[i]-'a'])
                --b[r[i]-'a'];
            else
            {
                ok=0;
                break;
            }
        }
        if(ok)
            g<<k<<'\n';
    }

}
