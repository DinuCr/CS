#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <iomanip>

using namespace std;

ifstream fin("harta2.in");
ofstream fout("harta2.out");

#define nmax 1001000

struct punct
{
    int x,y;
};

punct v[nmax];
int n,ans;

bool cmp(const punct &a,const punct &b)
{
    if(a.y==b.y)
        return a.x>b.x;
    return a.y>b.y;
}

bool verif(int k)
{
    int i,j;
    for(i=1; i<n; ++i)
    {
        j=i+1;
        while(v[i].y-v[j].y<k && j<=n)
        {
            if(abs(v[i].x-v[j].x)<k && j<=n)
                return 0;
            ++j;
        }
    }
    return 1;
}

void binary_s(int s, int d)
{
    if(s>d)
        return;
    int m = (s+d)/2;
    if(verif(m))
    {
        ans=m;
        binary_s(m+1,d);
    }
    else
    binary_s(s,m-1);
}


int main()
{
    int i;
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        fin>>v[i].x>>v[i].y;
        v[i].y*=3;
    }
    sort(v+1,v+n+1,cmp);
    binary_s(1,1100000);
    fout<<setprecision(4)<<fixed<<(float)ans/3;
}
