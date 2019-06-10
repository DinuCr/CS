#include <fstream>
#include <iostream>

using namespace std;

ifstream fin("xormax.in");
ofstream fout("xormax.out");

int curr[25];
int v[100100];
int h[1<<22];
int n,mx=-1,start,stop,i,j,nod;

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i];
        v[i]^=v[i-1];
        for(j=20; j>=0; --j)
            curr[20-j]=(bool)(v[i]&(1<<j));
        nod=1;
        for(j=0; j<21; ++j)
            if(h[(nod<<1)+!curr[j]])
                nod=(nod<<1)+!curr[j];
            else
                nod=(nod<<1)+curr[j];
        j=h[nod];
        if((v[j]^v[i])>mx)
        {
            mx=v[j]^v[i];
            start=j+1;
            stop=i;
        }
        nod=1;
        for(j=0; j<21; ++j)
            h[nod=(nod<<1)+curr[j]]=i;
    }
    fout<<mx<<' '<<start<<' '<<stop;
}
