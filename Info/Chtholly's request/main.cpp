#include <iostream>

using namespace std;

#define ll long long

int k,p,curr;
long long s;
int v[100];

void bkt(int x,int lim)
{
    if(x==lim+1)
    {
        ll a = 0;
        for(int i=1; i<=lim; ++i)
            a=a*10 + v[i];
        s+=a;
        s%=p;
        ++curr;
    }
    else
    if(x<=lim/2)
    {
        if(x==1)
        {
            for(int i=1; i<=9 && curr<k; ++i)
            {
                v[x]=i;
                bkt(x+1,lim);
            }
        }
        else
        {
            for(int i=0; i<=9 && curr<k; ++i)
            {
                v[x]=i;
                bkt(x+1,lim);
            }
        }
    }
    else
    {
        v[x]=v[lim-x+1];
        bkt(x+1,lim);
    }
}

int main()
{
    cin>>k>>p;
    int i=2;
    while(curr<k)
    {
        bkt(1,i);
        i+=2;
    }
    cout<<s;
}
