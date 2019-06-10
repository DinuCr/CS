#include <iostream>

using namespace std;

int v[200100],n,t,i,p,ok,t2;

int main()
{
    cin>>n>>t;
    for(i=1; i<n; ++i)
    {
        char c;
        cin>>c;
        if(c=='.')
        {
            p=i;
            --i;
        }
        else
            v[i]=c-'0';
    }
    ok=1;
    while(t && ok)
    {
        ok=0;
        for(i=p; i<n; ++i)
            if(v[i]>=5)
            {
                if(v[i]>=5 && v[i-1]==4 && i>p)
                {
                    ok=1;
                    while(v[i]>=5 && v[i-1]==4 && t)
                    {
                        v[i-1]=5;
                        n=i;
                        --t;
                        --i;
                    }
                    break;
                }
                else
                {
                    ok=1;
                    v[i-1]++;
                    n=i;
                    t2=v[i-1];
                    v[i-1]=t2%10;
                    t2/=10;
                    i=i-2;
                    while(t2 && i>=0)
                    {
                        t2+=v[i];
                        v[i]=t2%10;
                        t2/=10;
                        --i;
                    }
                    --t;
                    break;
                }
            }
    }
    if(v[0]!=0)
        cout<<v[0];
    for(i=1; i<n; ++i)
    {
        if(i==p)
            cout<<'.';
        cout<<v[i];
    }
}
