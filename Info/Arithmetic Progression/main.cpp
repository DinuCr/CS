#include <iostream>
#include <algorithm>

using namespace std;

long long n,v[100100],i,occ[100100],r[100100],k,j;

int main()
{
    cin>>n;
    if(n==1)
        cout<<-1;
    else
    {
        for(i=1; i<=n; ++i)
            cin>>v[i];
        sort(v+1,v+n+1);
        r[1]=v[2]-v[1];
        occ[1]++;
        k=1;
        for(i=2; i<n; ++i)
        {
            if(k>2)
            {
                cout<<0;
                return 0;
            }
            j=1;
            while(v[i+1]-v[i]!=r[j] && j<=k)
                ++j;
            if(j==k+1)
                r[++k]=v[i+1]-v[i];
            occ[j]++;
        }
        if(k==1 && r[1]==0)
            cout<<1<<'\n'<<v[1];
        else if(k==1)
        {
            if(r[1]%2==0 && n==2)
                cout<<3<<'\n'<<v[1]-r[1]<<' '<<v[1]+r[1]/2<<' '<<v[2]+r[1];
            else
                cout<<2<<'\n'<<v[1]-r[1]<<' '<<v[n]+r[1];
        }
        else if(k==2)
        {
            if(occ[1]>1 && occ[2]>1)
                cout<<0;
            else
            {
                if(r[2]>r[1])
                {
                    swap(r[1],r[2]);
                    swap(occ[1],occ[2]);
                }
                if(r[1]>r[2])
                {
                    if(r[2]*2==r[1] && occ[1]==1)
                    {
                        cout<<1<<'\n';
                        for(i=1; i<n; ++i)
                            if(v[i+1]-v[i]==r[1])
                                cout<<v[i]+r[2];
                    }
                    else
                        cout<<0;
                }
            }
        }
        else
            cout<<0;
    }
}
