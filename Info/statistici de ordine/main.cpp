#include <iostream>
#include <time.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
int v[3000100],i,n,k;
void kth(int ls,int ld)
{
    int m,x,i=ls,j=ld;
    m=ls+rand()%(ld-ls+1);
    x=v[m];
    do
    {
        while(v[i]<x && i<ld)
            i++;
        while(v[j]>x && j>ls)
            j--;
        if(i<=j)
            swap(v[i],v[j]),i++,j--;
    }while(i<=j);
    if(ls<j && k<=j && k>=ls)
    kth(ls,j);
    else
    if(ld>i && k<=ld && k>=i)
    kth(i,ld);
}
ifstream f("sdo.in");
ofstream g("sdo.out");
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
        f>>v[i];
    srand(time(NULL));
    kth(1,n);
    g<<v[k];
}
