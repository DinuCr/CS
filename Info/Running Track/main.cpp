#include <iostream>
#include <cstring>
using namespace std;
int n,p,v[2200][2],x,i,m,ok;
char s1[2200],s2[2200];
int caut(int x)
{
    int j=x,i=0,i1,i2,mx=0,nr;
    while(i<n && j<m)
    {
        nr=0;
        while(s1[i]==s2[j] && i<n && j<m)
            i++,j++,nr++;
        if(nr>mx)
        {
            i1=i-nr+1;
            i2=i;
            mx=nr;
        }
        j-=nr;
        i-=nr-1;
    }
    j=x;
    i=n-1;
    while(i>=0 && j<m)
    {
        nr=0;
        while(s1[i]==s2[j] && i>=0 && j<m)
            i--,j++,nr++;
        if(nr>mx)
        {
            i1=i+nr+1;
            i2=i+2;
            mx=nr;
        }
        j-=nr;
        i+=nr-1;
    }
    p++;
    v[p][0]=i1;
    v[p][1]=i2;
    return mx;
}
int main()
{
    cin.getline(s1,2200);
    cin.getline(s2,2200);
    i=0;
    n=strlen(s1);
    m=strlen(s2);
    while(i<m)
    {
        x=caut(i);
        if(x)
            i+=x;
        else
        {
            cout<<-1;
            ok=1;
            break;
        }
    }
    if(!ok)
    {
        cout<<p<<'\n';
        for(i=1; i<=p; i++)
            cout<<v[i][0]<<' '<<v[i][1]<<'\n';
    }
}
