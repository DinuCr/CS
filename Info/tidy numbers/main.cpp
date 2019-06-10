#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("tidy.in");
ofstream fout("tidy.out");

#define ll long long

int main()
{
    int t,cnt=0;
    fin>>t;
    for(cnt = 1; cnt<=t; ++cnt)
    {
        ll n;
        fin>>n;
        int v[100];
        v[0]=0;
        while(n)
        {
            v[++v[0]]=n%10;
            n/=10;
        }
        n = v[0];
        for(int i=1; i<=(n>>1); ++i)
            swap(v[i],v[n-i+1]);
        int mx = 0,ok=1;
        for(int i=2; i<=n; ++i)
        {
            if(v[i]<v[i-1])
            {
                int p = i;
                while(v[i]<=v[i-1] && i>1)
                {
                    v[i]=9;
                    --i;
                }
                v[i]--;
                for( i=p ; i<=n; ++i)
                    v[i]=9;
                break;
            }
        }
        fout<<"Case #"<<cnt<<": ";
        for(int i=v[1]==0?2:1; i<=n; ++i)
            fout<<v[i];
        fout<<'\n';
    }
}
