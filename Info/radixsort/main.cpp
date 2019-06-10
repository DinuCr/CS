#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("radixsort.in");
ofstream fout("radixsort.out");

int v[10000010];
int tmp[10000010];
int n,a,c,i;

void radix(int v[], int tmp[], int byte)
{
    int i;
    int cnt[1<<8];
    int w[1<<8];

    memset(w, 0, sizeof(w));

    int aux = byte*8;
    int p = (1<<8) - 1;

    for(i=1; i<=n; ++i)
        ++w[(v[i]>>aux) & p];

    cnt[0]=0;
    for(i=1; i<=p; ++i)
        cnt[i]=cnt[i-1]+w[i-1];
    for(i=1; i<=n; ++i)
        tmp[++cnt[(v[i]>>aux)&p]]=v[i];
}

int main()
{
    fin>>n>>a>>v[1]>>c;

    v[1]%=c;

    for(i=2; i<=n; ++i)
        v[i]=(1LL*a*v[i-1]+v[1])%c;

    for(i=0; i<4; ++i)
        if(i&1)
            radix(tmp, v, i);
        else
            radix(v, tmp, i);

    for(i=1; i<=n; i+=10)
        fout<<v[i]<<' ';
}
