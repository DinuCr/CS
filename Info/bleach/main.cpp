#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("bleach.in");
ofstream fout("bleach.out");

long long v[1100];
long long i,k,nr,n,s;

void up(int x)
{
    while(x>1 && v[x/2]>v[x])
    {
        swap(v[x/2],v[x]);
        x/=2;
    }
}

void down(int p)
{
    if((p<<1)<=k && (p<<1)+1<=k && v[p<<1]<v[(p<<1)+1] && v[p<<1]<v[p])
    {
        swap(v[p],v[p<<1]);
        down(p<<1);
    }
    else if((p<<1)<=k && (p<<1)+1<=k && v[p<<1]>v[(p<<1)+1] && v[(p<<1)+1]<v[p])
    {
        swap(v[p],v[(p<<1)+1]);
        down((p<<1)+1);
    }
    else if((p<<1)<=k && v[p<<1]<v[p])
    {
        swap(v[p],v[p<<1]);
        down(p<<1);
    }
}

int main()
{
    fin>>n>>k;
    ++k;
    //bag primele k in heap
    for(i=1; i<=k; ++i)
    {
        fin>>v[i];
        up(i);
    }
    //prelucrez in continuare sirul, si scot cate un element(minimul) de fiecare data cand adaug

    for(i=k+1; i<=n; ++i)
    {
        s-=v[1];
        if(s<0)
        {
            nr-=s;
            s=0;
        }
        s+=2*v[1];

        fin>>v[k+1];
        swap(v[k+1],v[1]);
        down(1);
    }

    s-=v[1];
    if(s<0)
    {
        nr-=s;
        s=0;
    }
    s+=2*v[1];


    //golesc heapul
    while(k>1)
    {
        swap(v[1],v[k]);
        --k;
        down(1);

        s-=v[1];
        if(s<0)
        {
            nr-=s;
            s=0;
        }
        s+=2*v[1];
    }
    fout<<nr;
}
