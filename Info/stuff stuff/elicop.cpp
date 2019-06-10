#include<iostream>
#include<fstream>
#include<cmath>
using namespace std;
int n,m,i,j,k,n2=0,n1=0,x,nr[2],v[41];
char a[101][101];
struct ielicoptierie
{
    int x1,x2,y1,y2,z;
}c;
int yolo(ielicoptierie b)
{
    int c,i,j,k=1,w;w=abs(b.y1-b.x1)+1;nr[0]=0;nr[1]=0;if(b.x1>b.y1)c=-1;else c=1;
    if(b.z==-1)
    {
        if(b.x1>b.y1){swap(b.x1,b.y1);swap(b.x2,b.y2);}
        i=b.x1;j=b.x2;w=b.y1-b.x1+1;k=1;nr[a[i][j]]++;
        if(b.x2<b.y2)
        {
            while(k<w)
            {
                i=b.x1+k;for(j=b.x2;j<b.x2+1+k;j++)nr[a[i][j]]++;
                k++;
            }
        }
        else
        {
            while(k<w)
            {
                i=b.x1+k;for(j=b.x2-k;j<=b.x2;j++)nr[a[i][j]]++;
                k++;
            }
        }
        if(nr[0]>nr[1])return 0;
        else{if(!nr[0])return 1;else return 2;}
    }
    else
    {
        if(b.x1<b.y1){swap(b.x1,b.y1);swap(b.x2,b.y2);}
        i=b.x1;j=b.x2;w=b.x1-b.y1+1;k=1;nr[a[i][j]]++;
        if(b.x2<b.y2)
        {
            while(k<w)
            {
                i=b.x1-k;for(j=b.x2;j<b.x2+k+1;j++)nr[a[i][j]]++;
                k++;
            }
        }
        else
        {
            while(k<w)
            {
                i=b.x1-k;for(j=b.x2-k;j<=b.x2;j++)nr[a[i][j]]++;
                k++;
            }
        }
        if(nr[0]>nr[1])return 0;
        else{if(!nr[0])return 1;else return 2;}
    }
}
int main()
{
    ifstream f("elicop.in");f>>m>>n;for(i=1;i<=m;i++)for(j=1;j<=n;j++){f>>a[i][j];a[i][j]=a[i][j]-'0';}f>>k;for(i=1;i<=k;i++){f>>c.x1>>c.x2>>c.y1>>c.y2>>c.z;x=yolo(c);if(!x){n2++;v[n2]=i;}if(x==1)n1++;}
    f.close();
    ofstream g("elicop.out");g<<n1<<'\n'<<n2<<" ";
    for(i=1;i<=n2;i++)g<<v[i]<<" ";
    g.close();
    return 0;
}
