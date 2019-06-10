#include<iostream>
#include<fstream>
using namespace std;
FILE *f=fopen("cifre5.in","r");
FILE *g=fopen("cifre5.out","w");
int v[10],w[10],nr[2][100002],i,j,x,n;
unsigned long long s;
int main()
{
    fscanf(f,"%d",&n);
    for(i=1;i<=n;i++)
    {
        fscanf(f,"%d",&x);
        j=0;
        if(x>0)
        {
        while(x>0)
        {
            w[x%10]++;
            x/=10;
            j++;
        }
        v[j]++;
        }
        else
        {
            v[1]++;
            w[0]++;
        }
    }
    j=9;
    i=1;
    while(i<=n)
    {
        x=v[j];
        while(x!=0)
        {
            nr[0][i]=j;
            x--;
            i++;
        }
        j--;
    }
    j=9;
    while(nr[0][n]!=0)
    {
        x=nr[0][1];
        i=1;
        while(nr[0][i]==x)
            i++;
        i--;
        while(i>0)
        {
            while(w[j]==0)
                j--;
            nr[1][i]=nr[1][i]*10+j;
            nr[0][i]--;
            w[j]--;
            i--;
        }
    }
    for(i=1;i<=n;i++)
        s+=nr[1][i];
    fprintf(g,"%lld\n",s);
    for(i=1;i<=n;i++)
        fprintf(g,"%d\n",nr[1][i]);
    fclose(g);
    return 0;
}
