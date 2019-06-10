#include <iostream>
#include <fstream>
using namespace std;
ifstream f("broscute.in");
ofstream g("broscute.out");
int i,n,v[1100],w[1100],poz[1100],p,c,nr,ok;
inline bool verif()
{
    for(int i=1; i<=n; i++)
        if(v[i]!=w[i])
            return 0;
    return 1;
}
inline void gen()
{
    if(c==1)
        nr++;
    else
        g<<v[poz[w[p]]]<<' '<<poz[w[p]]<<' '<<p<<'\n';
    swap(v[poz[w[p]]],v[p]);
    swap(poz[w[p]],p);
}
int main()
{
    f>>n>>c;
    n++;
    for(i=1; i<=n; i++)
    {
        f>>v[i];
        poz[v[i]]=i;
        if(v[i]==0)
            p=i;
    }
    for(i=1; i<=n; i++)
        f>>w[i];
    if(verif())
        g<<"broscutele nu se joaca"<<'\n';
    else
    {
        ok=1;
        while(ok)
        {
            if(w[p]!=0)
                gen();
            else
            {
                for(i=1; i<=n; i++)
                    if(v[i]!=w[i])
                    {
                        swap(v[i],v[p]);
                        swap(i,p);
                        poz[v[i]]=i;
                        g<<v[i]<<' '<<p<<' '<<i<<'\n';
                        break;
                    }
                gen();
            }
            ok=!verif();
        }
        if(c==1)
            g<<nr;
    }
}
