#include <iostream>
#include <cstring>

using namespace std;

char s[1000100];
int nr4,nr7,i,n,ok,okt,l,l7,pr;

int main()
{
    cin>>s;
    n=strlen(s);
    ok=1;
    if(n%2==1)
    {
        for(i=1; i<=n/2+1; ++i)
            cout<<4;
        for(i=1; i<=n/2+1; ++i)
            cout<<7;
    }
    else
    {
        ok=1;
        okt=1;
        pr=1000000;
        for(i=0; i<n && okt==1; ++i)
            if(ok)
            {
                if(s[i]-'0'<4 && nr4<n/2)
                {
                    nr4++;
                    ok=0;
                    l=i;
                }
                else if(s[i]-'0'<=4  && nr4<n/2)
                    nr4++,l=i,pr=min(pr,i);
                else if(s[i]-'0'<7 && nr7<n/2)
                {
                    nr7++;
                    ok=0;
                    l7=i;
                }
                else if(s[i]-'0'<=7 &&  nr7<n/2)
                    nr7++,l7=i;
                else if((pr<=l7 && nr4>0))
                {
                    okt=2;
                }
                else
                    okt=0;
            }
            else
            {
                if(nr7>n/2)
                {
                    okt=0;
                    break;
                }
                while(nr7<n/2)
                    nr7++;
                while(nr4<n/2)
                    nr4++;
            }
        if(okt==1)
        {
            ok=1;
            nr4=0;
            nr7=0;
            for(i=0; i<n; ++i)
                if(ok)
                {
                    if(s[i]-'0'<4 && nr4<n/2)
                    {
                        cout<<4;
                        nr4++;
                        ok=0;
                    }
                    else if(s[i]-'0'==4 && nr4<n/2)
                    {
                        cout<<4;
                        nr4++;
                    }
                    else if(s[i]-'0'<7 && nr7<n/2)
                    {
                        cout<<7;
                        nr7++;
                        ok=0;
                    }
                    else if(s[i]-'0'==7 && nr7<n/2)
                    {
                        cout<<7;
                        nr7++;
                    }
                }
                else
                {
                    while(nr4<n/2)
                    {
                        nr4++;
                        cout<<4;
                    }
                    while(nr7<n/2)
                    {
                        nr7++;
                        cout<<7;
                    }
                    break;
                }
        }
        else if(okt==0)
        {

            for(i=1; i<=n/2+1; ++i)
                cout<<4;
            for(i=1; i<=n/2+1; ++i)
                cout<<7;
        }
        else if(okt==2)
        {
            ok=1;
            nr4=0;
            nr7=0;
            for(i=0; i<l; ++i)
                if(ok)
                {
                    if(s[i]-'0'<4 && nr4<n/2)
                    {
                        cout<<4;
                        nr4++;
                        ok=0;
                    }
                    else if(s[i]-'0'==4 && nr4<n/2)
                    {
                        cout<<4;
                        nr4++;
                    }
                    else if(s[i]-'0'<7 && nr7<n/2)
                    {
                        cout<<7;
                        nr7++;
                        ok=0;
                    }
                    else if(s[i]-'0'==7 && nr7<n/2)
                    {
                        cout<<7;
                        nr7++;
                    }
                }
            cout<<7;
            nr7++;
            while(nr4<n/2)
            {
                cout<<4;
                nr4++;
            }
            while(nr7<n/2)
            {
                cout<<7;
                nr7++;
            }
        }
    }
}
