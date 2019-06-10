#include<iostream>
int p[100],n,i,j,k,aux;
using namespace std;
int main()
{
    cout<<"n=";cin>>n;
    for(i=1;i<=n;i++)cin>>p[i];
    for(i=n-1;i&&p[i]>p[i+1];i--);
    if(!i)cout<<"Nu exista succesor";
     else
        { for(j=n;p[j]<p[i];j--);
          aux=p[i];p[i]=p[j];p[j]=aux;
     for(j=i+1,k=n;j<k;j++,k--)
          {
              aux=p[j];p[j]=p[k];p[k]=aux;
          }
        }
    for(i=1;i<=n;i++)cout<<p[i]<<" ";


}
