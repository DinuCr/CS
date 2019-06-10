#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("petrica.in");
ofstream fout("petrica.out");

#define nmax 205

vector <int> v[nmax];
int ppl[nmax];
int viz[nmax];
int ls[nmax];
int ld[nmax];
int poz[nmax];
int nr[nmax];
int w[nmax];
int k,n,i,sum,a,b,c,d,as,bs,cs,ds,j;

void df(int x)
{
    poz[x]=++k;
    w[k]=ppl[x];
    ls[x]=k;
    viz[x]=1;
    for(auto it:v[x])
        if(!viz[it])
        {
            df(it);
        }
    ld[x]=k;
}

void sorteaza(int &a,int &b, int &c)
{
    if(poz[b]<poz[a])
        swap(a,b);
    if(poz[c]<poz[a])
        swap(a,c);
    if(poz[c]<poz[b])
        swap(b,c);
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>ppl[i];
        sum+=ppl[i];
    }
    for(i=1; i<n; ++i)
    {
        fin>>a>>b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    df(1);
    for(i=1; i<=n; ++i)
        w[i]+=w[i-1];
    for(i=1; i<=n; ++i)
        nr[i]=w[ld[i]]-w[ls[i]-1];
    int ans = 1e9;
    for(i=1; i<n; ++i)
        for(j=i+1; j<n; ++j)
            for(k=j+1; k<=n; ++k)
            {
                a = i;
                b = j;
                c = k;
                sorteaza(a,b,c);
                if(poz[b]<=ld[a])
                {
                    if(poz[c]<=ld[b])
                    {
                        cs = nr[c];
                        bs = nr[b]-nr[c];
                        as = nr[a]-nr[b];
                        ds = sum-nr[a];
                    }
                    else
                    if(poz[c]<=ld[a])
                    {
                        cs = nr[c];
                        bs = nr[b];
                        as = nr[a] - nr[b] - nr[c];
                        ds = sum - nr[a];
                    }
                    else
                    {
                        cs = nr[c];
                        bs = nr[b];
                        as = nr[a] - nr[b];
                        ds = sum - nr[a] - nr[c];
                    }
                }
                else
                {
                    if(poz[c]<=ld[b])
                    {
                        cs = nr[c];
                        bs = nr[b] - nr[c];
                        as = nr[a];
                        ds = sum - nr[a] - nr[b];
                    }
                    else
                    {
                        cs = nr[c];
                        bs = nr[b];
                        as = nr[a];
                        ds = sum - nr[a] - nr[b] - nr[c];
                    }
                }
                ans = min(ans,max(as,max(bs,max(cs,ds)))-min(as,min(bs,min(cs,ds))));
            }
    fout<<ans;
}
