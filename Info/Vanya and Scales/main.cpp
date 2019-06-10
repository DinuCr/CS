#include<iostream>
using namespace std;
int n,m,i,v[1005],ok;
int main()
{
    cin>>m>>n;
    i=1;
    while(n>0)
    {
        v[i]=n%m;
        n/=m;
        i++;
    }
    n=i-1;ok=true;
    for(i=n;i>0;i--)
    {
        if(v[i]==m-2 && v[i-1]!=0 && v[i-1]!=1)
            {
                while(v[i]<=v[i-1])
                i--;
                if(v[i]!=m-1)
                ok=false;
            }
        else
        if(!(v[i]==0 || v[i]==1 || (v[i]==m-1 && (v[i+1]==0 || v[i+1]==m-1))))
        ok=false;

    }
    if(ok)
        cout<<"YES";
    else
        cout<<"NO";
}
