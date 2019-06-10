#include<iostream>
#include<fstream>
using namespace std;
ifstream f("lsc.in");
int i,n,m,x[100],y[100],lsc[100][100],d[100],j;
void optim()
{
    int p,k,h;
    p=0;
    for(k=1;k<=n;k++)
        for(h=1;h<=m;h++)
            if(x[k]==y[h])
                lsc[k][h]=lsc[k-1][h-1]+1;
            else
                if(lsc[k-1][h]>lsc[k][h-1])
                    lsc[k][h]=lsc[k-1][h];
                else
                    lsc[k][h]=lsc[k][h-1];
}
void sol()
{
    int i,k,h;
    i=0;
    for(k=n,h=m;lsc[k][h];)
        if(x[k]==y[h])
        {
            d[i++]=x[k];
            k--;
            h--;
        }
        else
            if(lsc[k][h]==lsc[k-1][h])
                k--;
            else
                h--;
    for(k=i-1;k>=0;k--)
        cout<<d[k]<<' ';
}
int main()
{
    f>>n>>m;
    for(i=1;i<=n;i++)
        f>>x[i];
    for(i=1;i<=m;i++)
        f>>y[i];
    optim();
    sol();
    return 0;
}
