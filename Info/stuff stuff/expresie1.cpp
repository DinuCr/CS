#include<iostream>
#include<cstring>
#include<fstream>
using namespace std;
char fp[100],exp[100],st[100],c;
int i,n,x0,x1,k,j,v[100],nst[100];
ifstream f("expresie.in"),g("valori.in");
int prior(char c)
{
 if(c=='(' ) return 0;
 if(c=='+' || c=='-') return 1;
 if(c=='*'||c=='/') return 2;
}
void pstiva(int &k,char c)
{
    k++;st[k]=c;
}
void  sstiva(int &k, char &c)
{
  c=st[k];k--;
}
void valexp()
{int k1=-1,x;
 while(g>>c>>x)v[c-'a']=x;
 for(j=0;j<=n;j++)
  if(fp[j]>='a' && fp[j]<='z'){k1++;nst[k1]=v[fp[j]-'a'];}
     else {
           if(fp[j]=='-')nst[k1-1]-=nst[k1--];
           if(fp[j]=='+')nst[k1-1]+=nst[k1--];
           if(fp[j]=='*')nst[k1-1]*=nst[k1--];
           if(fp[j]=='/')nst[k1-1]/=nst[k1--];
           }
cout<<"valoarea"<<nst[0]<<'\n';
g.close();
}

void expresie()
{
char c1;
k=-1;j=-1;
 while(f>>c)
   {
   if(c=='(') pstiva(k,c);
   if(c==')') {while(st[k]!='('){sstiva(k,c1);j++;fp[j]=c1;};sstiva(k,c1);}
    if(c>='a' && c<='z'){j++;fp[j]=c;}
             if(c=='+' || c=='-' ||c=='*' || c=='/')
                     if(prior(st[k])>=prior(c))
                          {  while(prior(st[k])>=prior(c)){sstiva(k,c1);
                                                         j++;fp[j]=c1;
                                                         }
                             //sstiva(k,c1);
                             pstiva(k,c);
                          } else
                             pstiva(k,c);

   }

f.close();
n=j;
cout<<"fp="<<fp<<'\n';
valexp();

}
int main()
{
    //cout<<"expresia=";cin>>exp;
    expresie();
    return 0;
}
