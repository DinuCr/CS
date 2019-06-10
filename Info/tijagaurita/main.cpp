#include<iostream>
using namespace std;
int n,i,v[100],w[100],nr,k,l,ok;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>v[i];
    }
    for(i=1;i<=n;i++)
    {
        cin>>w[i];
    }
    for(i=1;i<=n;i++)
    if(v[i])
    {
        k=i;
        l=i;
        ok=false;
        while(k && l<=n && !ok)
        {
            if(v[k] || v[l])
                ok=false;
            k--;
            l++;
        }
        nr+=l-i-1;
    }
    cout<<nr;
}
