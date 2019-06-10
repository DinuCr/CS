#include <iostream>
#include <fstream>

using namespace std;

#define nmax 11000

ifstream fin("interclasare.in");
ofstream fout("interclasare.out");

int a[nmax];
int b[nmax];
int da[nmax];
int db[nmax];
int sira[nmax];
int sirb[nmax];
int ansa[nmax];
int ansb[nmax];
int q[nmax];
int n,m,i,p,s,d,l,t,u,mx,j,ia,jb,ib,k;

void answera(int i)
{
    if(sira[i]!=0)
        answera(sira[i]);
    ++t;
    ansa[t]=i;
}

void answerb(int i)
{
    if(sirb[i]!=0)
        answerb(sirb[i]);
    ++u;
    ansb[u]=i;
}

int main()
{
    fin>>n;
    mx=0;
    for(i=1; i<=n; ++i)
    {
        fin>>a[i];
        s=1;
        d=l;
        p=0;
        while(s<=d)
        {
            int m=(s+d)/2;
            if(a[i]>=a[q[m]])
                s=m+1,p=m;
            else
                d=m-1;
        }
        if(p+1>l)
            ++l;
        q[p+1]=i;
        da[i]=p+1;
        sira[i]=q[p];
        mx=max(mx,da[i]);
    }
    for(i=n; i>0; --i)
        if(da[i]==mx)
        {
            answera(i);
            break;
        }

    fin>>m;
    l=0;
    mx=0;
    for(i=1; i<=m; ++i)
    {
        fin>>b[i];
        s=1;
        d=l;
        p=0;
        while(s<=d)
        {
            int m=(s+d)/2;
            if(b[i]>=b[q[m]])
                s=m+1,p=m;
            else
                d=m-1;
        }
        if(p+1>l)
            ++l;
        q[p+1]=i;
        db[i]=p+1;
        sirb[i]=q[p];
        mx=max(mx,db[i]);
    }
    for(i=n; i>0; --i)
        if(db[i]==mx)
        {
            answerb(i);
            break;
        }
    fout<<t+u<<'\n';
    i=ia=j=jb=1;
    while(i<=t && ia<=n && j<=u && jb<=m)
    {
        while(ia<ansa[i])
        {
            fout<<a[ia]<<' ';
            ++ia;
        }
        while(jb<ansb[j])
        {
            fout<<b[jb]<<' ';
            ++jb;
        }
        if(a[ansa[i]]<b[ansb[j]])
        {
            fout<<a[ansa[i]]<<' ';
            ++i;
            ++ia;
        }
        else
        {
            fout<<b[ansb[j]]<<' ';
            ++j;
            ++jb;
        }
    }
    if(i==t+1 || ia==n+1)
    {
        for(k=ia; k<=n; ++k)
            fout<<a[k]<<' ';
        for(k=jb; k<=m; ++k)
            fout<<b[k]<<' ';
    }
    else
    {
        for(k=ia; k<=n; ++k)
            fout<<a[k]<<' ';
        for(k=jb; k<=m; ++k)
            fout<<b[k]<<' ';
    }
}
