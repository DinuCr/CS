#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("lazy.in");
ofstream fout("lazy.out");

#define nmax 110

int v[nmax],n,cnt,i,j,ans;

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    int t;
    fin>>t;
    while(++cnt<=t)
    {
        fin>>n;
        for(i=1; i<=n; ++i)
            fin>>v[i];
        i = 1;
        j = n;
        ans = 0;
        sort(v+1,v+n+1,cmp);
        while(i<=j)
        {
            int c = v[i];
            int counter = 1;
            while(i<j && c*counter<50)
            {
                --j;
                ++counter;
            }
            if(counter*c>=50)
                ++ans;
            ++i;
        }
        f   out<<"Case #"<<cnt<<": "<<ans<<'\n';
    }
}
