#include <iostream>

using namespace std;

char v[300];
int n,i,j,a,b,nr,ok;

bool litera(char c)
{
    if(c!='_' && c!='(' && c!=')')
        return 1;
    return 0;
}

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i];
        if(ok)
        {
            if(litera(v[i]) && !litera(v[i-1]))
                ++b;
        }
        else
        {
            if(litera(v[i]))
                ++nr;
            else
            {
                a=max(a,nr);
                nr=0;
            }
        }
        if(v[i]=='(')
            ok=1;
        else
        if(v[i]==')')
            ok=0;
    }
    i=n+1;
    v[n+1]='_';
    if(ok)
        {
            if(litera(v[i]) && !litera(v[i-1]))
                ++b;
        }
        else
        {
            if(litera(v[i]))
                ++nr;
            else
            {
                a=max(a,nr);
                nr=0;
            }
        }
    cout<<a<<' '<<b;
}
