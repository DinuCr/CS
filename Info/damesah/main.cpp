#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("damesah.in");
ofstream fout("damesah.out");

int v[15][15];
int bkt[15];
int poz[15];
int diag1[50];
int diag2[50];
int n,nr;

void bact(int k)
{
    if(k==n+1)
    {
        ++nr;
        if(nr==1)
        {
            for(int i=1; i<=n; ++i)
                fout<<bkt[i]<<' ';
            fout<<'\n';
        }
    }
    else
    {
        for(int i=1; i<=n; ++i)
            if(!v[k][i] && !poz[i] && !diag1[i-k+15] && !diag2[i+k])
            {
                bkt[k]=i;
                poz[i]=1;
                diag1[i-k+15]=1;
                diag2[i+k]=1;
                bact(k+1);

                poz[i]=0;
                diag1[i-k+15]=0;
                diag2[i+k]=0;
            }
    }
}

int main()
{
    fin>>n;
    bact(1);
    fout<<nr;
}
