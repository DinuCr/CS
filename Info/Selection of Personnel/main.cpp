#include <iostream>
using namespace std;
int a[100001],b[100001],c[100001],n,i,k;
void Mult(int H[],int X)
{ int i;
  unsigned long T=0;
  for (i=1;i<=H[0];i++)
    { H[i]=H[i]*X+T;
      T=H[i]/10;
      H[i]=H[i]%10;
    }
  while (T)
    { H[++H[0]]=T%10;
      T/=10;
    }
}
unsigned long Divide(int A[], unsigned long X)
/* A <- A/X si intoarce A%X */
{ int i;
  unsigned long R=0;
  for (i=A[0];i;i--)
    { A[i]=(R=10*R+A[i])/X;
      R%=X;
    }
  while (!A[A[0]] && A[0]>1) A[0]--;
  return R;
}
void Add(int A[], int B[])
/* A <- A+B */
{ int i,T=0;
  if (B[0]>A[0])
    { for (i=A[0]+1;i<=B[0];) A[i++]=0;
      A[0]=B[0];
    }
    else for (i=B[0]+1;i<=A[0];) B[i++]=0;
  for (i=1;i<=A[0];i++)
    { A[i]+=B[i]+T;
      T=A[i]/10;
      A[i]%=10;
    }
  if (T) A[++A[0]]=T;
}
int main()
{
    cin>>n;
    k=5;
    a[0]=1;
    a[1]=1;
    for(i=k+1;i<=n;i++)
        Mult(a,i);
    for(i=n-k;i>1;i--)Divide(a,i);
    k=6;
    b[0]=1;
    b[1]=1;
    for(i=k+1;i<=n;i++)
        Mult(b,i);
    for(i=n-k;i>1;i--)Divide(b,i);
    k=7;
    c[0]=1;
    c[1]=1;
    for(i=k+1;i<=n;i++)
        Mult(c,i);
    for(i=n-k;i>1;i--)Divide(c,i);
    Add(a,b);
    Add(a,c);
    for(i=a[0];i>0;i--)cout<<a[i];
    return 0;
}
