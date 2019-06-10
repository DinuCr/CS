#include<iostream>
#include<algorithm>
using namespace std;
typedef struct coord
{
    int x,y;
};
unsigned long long i,j,n,p,k,ok,s,z,x,y;
coord v[2101];
unsigned long long w[10000000];
int main()
{
   cin>>n;
   for(i=1;i<=n;i++)
        cin>>v[i].x>>v[i].y;
   for(i=1;i<n;i++)
   for(j=i+1;j<=n;j++)
   {
       k++;
       x=v[i].x+v[j].x;
       y=v[i].y+v[j].y;
       w[k]=x*10000000000 +y;
   }
   ok=true;
   sort(w+1,w+k+1);
   i=1;
   while(i<=k)
   {
       j=i;
       while(w[i]==w[j+1])
        j++;
       s+=(j-i)*(j-i+1)/2;
       i=j+1;
   }
   cout<<s;
   return 0;
}
