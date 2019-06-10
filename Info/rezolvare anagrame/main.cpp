#include <iostream>
#include <stdio.h>
#include <cstring>
#include <fstream>
using namespace std;
int n,w[30],v[30],i,N;
char s[30],c;
ifstream f("rebus.in");
typedef struct sir
{
    char s[30];
};
sir B[80000];
inline int cmp(char a[],char b[])
{
    int n=min(strlen(a),strlen(b));
    for(int i=1; i<n; i++)
    {
        if(a[i]>b[i])
            return -1;
        if(a[i]<b[i])
            return 1;
    }
    return 0;
}
bool bs(int ls,int ld,char s[])
{
    if(ls>=ld)
        if(cmp(B[ls].s,s)!=0 && cmp(B[ld].s,s)!=0 && cmp(B[(ls+ld)/2].s,s)!=0)
            return 0;

    if(cmp(B[ls].s,s)==0 || cmp(B[ld].s,s)==0 || cmp(B[(ls+ld)/2].s,s)==0)
        return 1;
    else if(cmp(B[(ls+ld)/2].s,s)<0)
        return bs(ls,(ls+ld)/2-1,s);
    else
        return bs((ls+ld)/2+1,ld,s);
}
void bkt(int k)
{
    if(k==n+1)
    {
        if(bs(1,N,s))
        {
            for(int k=1;k<=n;k++)
            cout<<s[k];
            cout<<'\n';
        }
    }
    else
    {
        for(int j=0; j<26; j++)
            if(w[j]<v[j])
            {
                s[k]=j+'A';
                w[s[k]-'A']++;



                bkt(k+1);


                w[s[k]-'A']--;
            }
    }
}
int main()
{
    cin>>n;
    for(i=1; i<=n; i++)
    {
        cin>>c;
        v[c-'A']++;
    }
    sir a;
    i=0;
    while(!f.eof())
    {
        f.getline(a.s,30);
        B[++i]=a;
    }
    N=i;
    s[0]='-';
    bkt(1);
}
