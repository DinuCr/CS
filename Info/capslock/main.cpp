#include<iostream>
#include<cstring>
using namespace std;
int i,ok;
char v[102];
int main()
{
    cin>>v;
    ok=1;
    if(v[0]<='z' && v[0]>='a')
    for(i=1;i<strlen(v);i++)
    {
        if(v[i]<='z' && v[i]>='a')
        {
            ok=false;
            break;
        }
    }
    else
    {
        ok=1;
        for(i=0;i<strlen(v);i++)
            if(v[i]<='z' && v[i]>='a')
            {
                ok=false;
                break;
            }
    }
    if(!ok)
        cout<<v;
    else
    {
        if(v[0]<='z' && v[0]>='a')
        {
            v[0]-=32;
            for(i=1;i<strlen(v);i++)
                v[i]+=32;
            cout<<v;
        }
        else
        {
            for(i=0;i<strlen(v);i++)
                v[i]+=32;
            cout<<v;
        }
    }
    return 0;
}
