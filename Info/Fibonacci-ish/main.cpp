#include <iostream>
#include <algorithm>
using namespace std;
int v[1100];
int mx,i,j,k,n,x,ok,ls,ld,a,b,nr,p,m;
inline int bs(int left, int right,int value)
{
      while (left <= right) {
            int middle = (left + right) / 2;
            if (v[middle] == value)
                  return middle;
            else if (v[middle] > value)
                  right = middle - 1;
            else
                  left = middle + 1;
      }
      return left;
}

int main()
{
    cin>>n;
    for(i=0;i<n;++i)
        cin>>v[i];
    sort(v,v+n);
    mx=2;
    m=n-1;
    ok=1;
    for(i=0;i<m;++i)
    for(j=i+1;j<n;++j)
    {
        ld=j;
        ls=i;
        nr=2;
        while(ok)
        {
            nr++;
            p=bs(0,n-1,v[ls]+v[ld]);
            if(v[ls]+v[ld]==v[p])
            {
                ls=ld;
                ld=p;
            }
            else
                break;
        }
        mx=max(mx,nr-1);
    }
    cout<<mx;
}
