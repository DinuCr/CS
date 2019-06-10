#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("jstc.in");
ofstream fout("jstc.out");

char s[10010000];
int nxt[1001000];
int v[1001000];
int st[1001000];
long long ans;
int a,b,i,n,m,nr,lastx,ok;

void compute(int x)
{
    int k = 0;
    while(nxt[x]!=0 && nxt[x]!=x)
    {
        st[k++]=x;
        x=nxt[x];
    }

    if(nxt[x]==0)
        ok = -1;
    if(nxt[x]==x)
        ok = x;
    --k;
    for(int i=0; i<k; ++i)
        nxt[st[i]]=x;
}

int main()
{
    fin>>a>>b;
    fin>>s;
    int n = strlen(s);
    m=1;
    for(i=0; i<n; ++i)
    {
        switch(s[i])
        {
        case 'I':
            ++nr;
            v[++m]=nr;
            nxt[nr]=nr;
            break;
        case 'E':
            nxt[v[m]]=v[m]+1;
            --m;
            break;
        case 'Q':
            int x=1LL*(1LL*a*lastx+1LL*b)%(1LL*nr)+1;
            lastx=x;
            compute(x);
            ans+=1LL*ok;
            break;
        }
    }
    fout<<ans;
}
