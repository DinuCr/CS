#include <iostream>
#include <deque>
#include <fstream>
#include <algorithm>
#include <time.h>
#include <stdlib.h>
using namespace std;
ifstream f("amedie.in");
ofstream g("amedie.out");
deque <int> v;
struct pos
{
    int x,y;
}h[650000];
int w[810][810],n,m,q,i,j;
void qsort(int ls,int ld)
{
    int i,j,x;
    i=ls;
    j=ld;
    x=v[i+rand()%(j-i+1)];
    do
    {
        while(i<ld && v[i]<x)
            i++;
        while(j>ls && v[j]>x)
            j--;
        if(i<=j)
        {
            swap(v[i],v[j]);
            swap(w[h[i].x][h[i].y],w[h[j].x][h[j].y]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort(i,ld);
    if(j>ls)
        qsort(ls,j);
}
int main()
{
    f>>n>>m>>q;
    int x,N;
    char c;
    for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        f>>x;
        v.push_back(x);
        w[i][j]=v.size()-1;
        h[(i-1)*m+j-1].x=i;
        h[(i-1)*m+j-1].y=j;
    }
    srand(time(NULL));
    N=v.size();
    qsort(0,N-1);
    for(i=1;i<=q;i++)
    {
        f>>c;
        switch(c)
        {
        case 'C':
            f>>x;
            nr=0;
            for(j=1;j<=n;j++)
            if(w[j][x]!=-1)
            {
                v.erase(v.begin()+w[j][x]-nr);
                w[j][x]=-k;
                N--;
                nr++;
            }
            break;
        case 'L':
            f>>x;
            nr=0;
            for(j=1;j<=m;j++)
            if(w[x][j]!=-1)
            {
                v.erase(v.begin()+w[x][j]-nr);
                w[x][j]=-k;
                N--;
                nr++;
            }
            break;
        case 'Q':
            cout<<v[(N-1)/2]<<'\n';
        }
    }
}
