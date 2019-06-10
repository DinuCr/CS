#include<iostream>
#include<fstream>
using namespace std;
FILE *f=fopen("numere7.in","r");
FILE *g=fopen("numere7.out","w");
bool v[250005];
int i,n,j,x,y;
int main()
{
    fscanf(f,"%d",&n);
    x=n*n;
    for(i=1;i<=x;i++)
    {
        fscanf(f,"%d",&y);
        v[y]=1;
    }
    i=1;
    while(v[i]==1)
        i+=3;
    if(i-2>=1 && v[i-2]==0)
        i-=2;
    else
        if(i-1>=1 && v[i-1]==0)
        i--;
    j=x;
    while(v[j]==1)
        j-=3;
    if(v[j+2]==0 && j+2<=x)
        j+=2;
    else
        if(v[j+1]==0 && j+1<=x)
        j++;
    fprintf(g,"%d %d",i,j);
    fclose(g);
    return 0;
}
