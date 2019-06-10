#include <iostream>
#include <cstring>

using namespace std;

char s[50600];
int nr1,nr,n,i,j,k,ok,v[100],poz;

int main()
{
    cin.getline(s,50500);
    n=strlen(s);
    ok=0;
    if(n<26)
        cout<<-1;
    else
    {
        nr=0;
        for(j=0; j<26; ++j)
        {
            if(s[j]=='?')
                nr1++;
            else
            {
                if(v[s[j]-'A']==0)
                {
                    ++nr;
                }
                v[s[j]-'A']++;
            }
        }
        if(nr+nr1==26)
        {
            poz=i;
            ok=1;
        }
        for(i=0; j<n && !ok; ++j,++i)
        {
            if(s[i]=='?')
                nr1--;
            else
            {
                v[s[i]-'A']--;
                if(v[s[i]-'A']==0)
                    --nr;
            }
            if(s[j]=='?')
                nr1++;
            else
            {
                if(v[s[j]-'A']==0)
                {
                    ++nr;
                }
                v[s[j]-'A']++;
            }

            if(nr+nr1==26)
            {
                poz=i+1;
                ok=1;
            }
        }

        if(ok==0)
            cout<<-1;
        else
        {
            for(i=0; i<poz; ++i)
            if(s[i]!='?')
                cout<<s[i];
            else
                cout<<'A';
            i=poz;
            j=poz+25;
            char p='A';
            for(k=i; k<=j; ++k)
                if(s[k]!='?')
                    cout<<s[k];
                else
                {
                    while(v[p-'A']!=0)
                        ++p;
                    v[p-'A']=1;
                    cout<<p;
                }
            for(i=j+1; i<n; ++i)
                if(s[i]!='?')
                cout<<s[i];
            else
                cout<<'A';
        }

    }
}




