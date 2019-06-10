#include <iostream>
#include <cstring>

using namespace std;

char ans[5][30],s[50];
char c;
int i,pz1,pz2,prima,adoua,frv[50],ultima,j,k,contor;

int main()
{
    cin.getline(s,100);
    for(i=0; i<27; ++i)
        frv[s[i]-'A']++;
    for(i=0; i<26; ++i)
        if(frv[i]==2)
            c=i+'A';
    pz1=pz2=-1;
    for(i=0; i<27; ++i)
        if(s[i]==c)
        {
            if(pz1==-1)
                pz1=i;
            else
                pz2=i;
        }
    prima=pz1;
    adoua=pz2-pz1-1;
    ultima=26-pz2;
    if(pz2!=pz1+1)
    for(i=1; i<=13; ++i)
    {
        if((prima+ultima==1+(i-1)*2 && adoua==(13-i)*2) || (prima+ultima==(i-1)*2 && adoua==(13-i)*2+1))
        {
            ans[1][i]=c;
            for(j=i+1,k=pz1+1; j<=13 && k<pz2; ++j,++k)
                ans[1][j]=s[k];
            for(j=13; j>=i && k<pz2; --j,++k)
                ans[2][j]=s[k];

            for(j=i-1,k=pz1-1; j>0 && k>=0; --k,--j)
                ans[1][j]=s[k];
            for(j=1; k>=0; --k,++j)
                ans[2][j]=s[k];

            int ok;
            if(ans[2][i]==NULL)
                ok=0;
            else
                ok=1;
            for(j=i-ok,k=pz2+1; k<27 && j>0; --j,++k)
                ans[2][j]=s[k];
            for(j=1; k<27 ;++j,++k)
                ans[1][j]=s[k];

            contor=1;
            for(k=1; k<=2; ++k)
            {
                for(j=1; j<=13; ++j)
                    cout<<ans[k][j];
                cout<<'\n';
            }
            break;
        }
    }
    if(!contor)
    cout<<"Impossible";

}
