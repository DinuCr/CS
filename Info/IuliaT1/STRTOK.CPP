/* Am lucrat cu sirurile de caractere declarate ca pointeri. In acest
caz este obligatoriu sa se rezerve memorie pentru siruri. In sep se trec
separatorii care pot sa apara. La apelul p=strtok(s,sep) se retine in p
adresa primului cuvant si se pune in s in locul primului separator caracterul
NULL. In continuare se face cautarea urmatorului cuvant de la NULL spre dreapta
. Din acest motiv se apeleaza strtok cu parametrul  NULL.
OBS. Sirurile de caractere ce contin spatii nu se pot citi cu "cin>>",se
va citi doar primul cuvant pana la spatiu

  */
#include<iostream.h>
#include<string.h>
#include<alloc.h>
#include<stdio.h>
char *sep=" ,;.",*s,*p;
void test(char *s)
{ p=strtok(s,sep);
  while(p)
   {  cout<<p<<endl;
     p=strtok(NULL,sep);
   }
}
int  main()
{s=(char*)malloc(255); //Se mai putea declara  char s[255] si atunci nu se aloca memorie
cout<<"Introd. sirul";gets(s);
 test(s);
 getchar();
 return 0;
 }
