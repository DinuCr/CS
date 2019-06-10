#include<iostream>
#include<cmath>
#include<iomanip>
#include<cstring>
using namespace std;
int x1,k,r1,r2,i,c;
double p;
char s[11];
int main()
{
    cin>>s;
    for(i=0; i<strlen(s); i++)
        if(s[i]=='-')
            r1--;
        else
            r1++;
    cin>>s;
    for(i=0; i<strlen(s); i++)
        if(s[i]=='-')
            r2--;
        else if(s[i]=='?')
            k++;
        else
            r2++;
    if(r1==r2 && k==0)
        p=1;
    else if(abs(r1-r2)>abs(k))
        p=0;
    else
    {
        for(i=0; i<=k; i++)
            s[i]=0;
        while(s[1]==0)
        {
            c=0;
            for(i=1; i<=k; i++)
                if(s[i]==0)
                    c++;
                else
                    c--;
            if(r1+c==r2)
                x1++;
            if(r1-c==r2)
                x1++;
            i=k;
            while(s[i]==1)
            {
                s[i]=0;
                i--;
            }
            s[i]=1;
        }
        p=x1/pow(2,k);
    }
    cout<<fixed<<setprecision(12)<<p;
}
