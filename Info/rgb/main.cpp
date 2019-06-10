#include <fstream>

using namespace std;

ifstream fin("rgb.in");
ofstream fout("rgb.out");

int t,i,r,g,b,rr,gr,br,j;
int Min,Max;

int main()
{
    fin>>t;
    for(i=1;i<=t;i++)
    {
        fin>>r>>g>>b;
        Min=min(r,min(g,b));
        Max=max(r,max(g,b));
        if(Max>2*Min)fout<<-1<<'\n';
        else    if(r<=g&&r<=b)
        {
            gr=g-r;
            br=b-r;
            g=b=r;
            for(j=1;j<=r;j++)
                fout<<3+20*(j-1)<<" ";
            fout<<'\n';
            for(j=1;j<=g;j++)
                fout<<2+20*(j-1)<<" ";
            for(j=1;j<=gr;j++)
                fout<<5+20*(j-1)<<" ";
            fout<<'\n';
            for(j=1;j<=b;j++)
                fout<<4+20*(j-1)<<" ";
            for(j=1;j<=br;j++)
                fout<<1+20*(j-1)<<" ";
            fout<<'\n';
        }
        else if(g<=r&&g<=b)
        {
            rr=r-g;
            br=b-g;
            b=r=g;
            for(j=1;j<=r;j++)
                fout<<2+20*(j-1)<<" ";
            for(j=1;j<=rr;j++)
                fout<<5+20*(j-1)<<" ";
            fout<<'\n';
            for(j=1;j<=g;j++)
                fout<<3+20*(j-1)<<" ";
            fout<<'\n';
            for(j=1;j<=b;j++)
                fout<<4+20*(j-1)<<" ";
            for(j=1;j<=br;j++)
                fout<<1+20*(j-1)<<" ";
            fout<<'\n';
        }
        else if(b<=g&&b<=r)
        {
            rr=r-b;
            gr=g-b;
            r=g=b;
            for(j=1;j<=r;j++)
                fout<<2+20*(j-1)<<" ";
            for(j=1;j<=rr;j++)
                fout<<5+20*(j-1)<<" ";
            fout<<'\n';
            for(j=1;j<=g;j++)
                fout<<4+20*(j-1)<<" ";
            for(j=1;j<=gr;j++)
                fout<<1+20*(j-1)<<" ";
            fout<<'\n';
            for(j=1;j<=b;j++)
                fout<<3+20*(j-1)<<" ";
            fout<<'\n';
        }
    }
    return 0;
}
