#include <stdio.h>
#include <string.h>
#include <algorithm>
#define Nm 2003
#define L 203

using namespace std;

struct s{char S[L];};

int p,i,j,N,q,d,k,q1,q2,o,lqs,ii,jj; bool b[Nm];
char E[L],qs[L];
s C[Nm];

bool c(s i,s j)
{
    return(strcmp(i.S,j.S)<0);
}

int main()
{
    freopen("masca.in","r",stdin);
    freopen("masca.out","w",stdout);
    scanf("%d%s%d",&p,&E,&N);
    for(i=1;i<=N;i++)
     scanf("%s",&C[i].S);
    stable_sort(C+1,C+N+1,c);
    for(i=1;i<=N;i++)
    if(strcmp(C[i].S,C[i-1].S)) {b[i]=1; d++;}

    if(p==1) printf("%d",d);
    else
    {
        for(i=0;i<strlen(E);i++) if(E[i]=='*') {q++; if(q>1) break;}
        //cazul 1
        if (!q)
        {
            for(i=1;i<=N;i++)
             if(b[i])
             {
                if(strlen(C[i].S)==strlen(E))
                {
                    for(j=0;j<strlen(E);j++)
                     if((C[i].S[j]!=E[j])&&(E[j]!='?')) break;
                    if(j==strlen(E)) k++;
                }
             }
        }
        //cazul 2
        else if(q==1)
        {
            for(i=1;i<=N;i++)
             if(b[i])
             {
                if(strlen(C[i].S)>=strlen(E)-1)
                {
                    for(j=0;j<strlen(E);j++)
                     if((C[i].S[j]!=E[j])&&(E[j]!='?')) break;
                    if(E[j]=='*')
                    {for(j=1;j<=strlen(E);j++)
                      if((C[i].S[strlen(C[i].S)-j]!=E[strlen(E)-j])&&(E[strlen(E)-j]!='?')) break;
                    if(E[strlen(E)-j]=='*') k++;}
                }
             }
        }
        //cazul 3
        else
        {
            for(i=0;i<strlen(E);i++)
             if(E[i]=='*') {o++; if(o>1) break;}
             else if(o) qs[lqs++]=E[i];

            for(i=1;i<=N;i++)
             if(b[i])
              if(strlen(C[i].S)>=strlen(E)-2)
                 {
                     for(j=0;j<strlen(E);j++)
                      if((C[i].S[j]!=E[j])&&(E[j]!='?')) break;
                     if(E[j]=='*')
                     {
                         q1=j;
                         for(j=1;j<=strlen(E);j++)
                          if((C[i].S[strlen(C[i].S)-j]!=E[strlen(E)-j])&&(E[strlen(E)-j]!='?')) break;
                         if(E[strlen(E)-j]=='*')
                         {
                             q2=strlen(C[i].S)-j;
                             for(ii=q1;ii<=q2-lqs+1;ii++)
                             {
                                 for(jj=ii;jj<=ii+lqs-1;jj++)
                                  if((C[i].S[jj]!=qs[jj-ii])&&(qs[jj-ii]!='?')) break;
                                 if(jj==ii+lqs) {k++; break;}
                             }
                         }
                     }
                 }
        }
        printf("%d",k);
    }
    return 0;
}
