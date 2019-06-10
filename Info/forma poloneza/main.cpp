#include<iostream>
#include<fstream>
using namespace std;
ifstream f("fp.in");
ifstream g("valori.in");
char fp[100],x,st[100];
int k,i,p,v[100],y,nst[100];
int prioritate(char c)
{
    if(c=='(' || c==')')
        return 0;
    if(c=='-' || c=='+')
        return 1;
    else
        return 2;
}
int main()
{
    f>>x;
    while(!f.eof())
    {
        if(x<='z' && x>='a')
        {
            k++;
            fp[k]=x;
        }
        else
        {
            if(x=='(')
            {
                p++;
                st[p]='(';
            }
            else
            if(x==')')
            {
                while(st[p]!='(' && p>0)
                {
                    k++;
                    fp[k]=st[p];
                    p--;
                }
                p--;
            }
            else
            {
                while(prioritate(x)<prioritate(st[p]) && p>0)
                {
                    k++;
                    fp[k]=st[p];
                    p--;
                }
                p++;
                st[p]=x;
            }
        }
        f>>x;
    }
    while(p>0)
    {
        if(st[p]!=')' && st[p]!='(')
        {
            k++;
            fp[k]=st[p];
        }
        p--;
    }
    g>>x;
    while(!g.eof())
    {
        g>>y;
        v[x-'a']=y;
        g>>x;
    }
    p=0;
    for(i=1;i<=k;i++)
    {
        if(fp[i]<='z' && fp[i]>='a')
        {
            p++;
            nst[p]=v[fp[i]-'a'];
        }
        else
        {
            switch(fp[i])
            {
            case '+':
                nst[p-1]=nst[p]+nst[p-1];
                p--;
                break;
            case '-':
                nst[p-1]=nst[p-1]-nst[p];
                p--;
                break;
            case '/':
                nst[p-1]=nst[p-1]/nst[p];
                p--;
                break;
            case '*':
                nst[p-1]=nst[p-1]*nst[p];
                p--;
                break;
            }
        }
    }
    for(i=1;i<=k;i++)
        cout<<fp[i];
    cout<<'\n'<<nst[1];
    f.close();
    return 0;
}
