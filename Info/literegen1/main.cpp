#include <iostream>
#include <cmath>

using namespace std;

char v[30];
int n;

void bkt(int k)
{
    if(k==n && abs(v[n]-v[n-1])==1)
    {
        cout<<v+1<<'\n';
    }
    if(k<n)
    {
        if(v[k-1]>'a')
        {
            v[k]=v[k-1]-1;
            bkt(k+1);
        }
        if(v[k-1]<'z')
        {
            v[k]=v[k-1]+1;
            bkt(k+1);
        }
    }
}

int main()
{
    cin>>n;
    v[1]=v[n]='a';
    bkt(2);
}
