#include <iostream>
#include<cmath>
#include<fstream>
using namespace std;
long long v[100001][2],i,j,mx,n,d,s;
ifstream f("in.in");
void qsort(int ls,int ld)
{
    long long m,i,j,z;
    m=(ls+ld)/2;
    i=ls;
    j=ld;
    z=v[m][0];
    do
    {
        while(v[i][0]<z)
            i++;
        while(v[j][0]>z)
            j--;
        if(i<=j)
        {
            swap(v[i][0],v[j][0]);
            swap(v[i][1],v[j][1]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort(i,ld);
    if(j>ls)
        qsort(ls,j);
}
void qsort1(int ls,int ld)
{
    long long m,i,j,z;
    m=(ls+ld)/2;
    i=ls;
    j=ld;
    z=v[m][1];
    do
    {
        while(v[i][1]<z)
            i++;
        while(v[j][1]>z)
            j--;
        if(i<=j)
        {
            swap(v[i][0],v[j][0]);
            swap(v[i][1],v[j][1]);
            i++;
            j--;
        }
    }while(i<=j);
    if(i<ld)
        qsort1(i,ld);
    if(j>ls)
        qsort1(ls,j);
}
int main()
{
    cin>>n>>d;
    for(i=1;i<=n;i++)
        cin>>v[i][0]>>v[i][1];
    qsort(1,n);
    for(i=1;i<n;i++)
    {
        j=i;
        while(v[j-1][0]==v[i][0] && j<n)
            j++;
        qsort1(i,j);
    }
    mx=v[n][1];s=v[n][1];i=n;j=n-1;
    while(i>0)
    {
        while(abs(v[i][0]-v[j][0])<d && j>0)
        {
            s+=v[j][1];
            j--;
        }
        mx=max(s,mx);
        s-=v[i][1];
        i--;
    }
    cout<<mx;
}
