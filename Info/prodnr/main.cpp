#include<iostream>
#include<fstream>
using namespace std;
ifstream f("prodnr.in");
ofstream g("prodnr.out");
typedef struct num
{
    int x,y;
};
num v[9600];
bool w[100000];
int i,j,k,n,a,nr;
char x;
int main()
{
    for(i=3;i<50000;i+=2)
    {
        for(j=i*2;j<100000;j+=i)
            w[j]=1;
    }
    v[1].x=2;
    k=1;
    for(i=3;i<=100000;i+=2)
    if(w[i]==0)
    {
        k++;
        v[k].x=i;
    }
    f>>x;
    n=x-'0';
    while(!f.eof())
    {

        nr++;
        a=0;
        for(i=1;i<=n;i++)
        {
            f>>x;
            a=a*10+(x-'0');
        }
        i=1;
        while(a!=1)
        {
            while(a%v[i].x==0)
            {
                v[i].y++;
                a/=v[i].x;
            }
            i++;
        }
        f>>x;
        n=x-'0';
    }
    g<<nr<<'\n';
    for(i=1;i<=k;i++)
        if(v[i].y!=0)
        g<<v[i].x<<' '<<v[i].y<<'\n';
    f.close();
    g.close();
    return 0;
}
