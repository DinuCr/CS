#include <iostream>

using namespace std;

char ans[100100];
int a,b,ka,kb,k,n,i;

int main()
{
    cin>>n>>k>>a>>b;
    ka=0;
    kb=0;
    for(i=1; i<=n; ++i)
    {
        if(a>b)
        {
            if(ans[i-1]=='G' || i==1)
            {
                if(ka<k && a>0)
                {
                    ++ka;
                    --a;
                    ans[i]='G';
                }
                else
                {
                    ka=0;
                    kb=0;
                    if(b>0)
                    {
                        ++kb;
                        --b;
                        ans[i]='B';
                    }
                }
            }
            else
            {
                kb=0;
                ka=0;
                if(ka<k && a>0)
                {
                    ++ka;
                    --a;
                    ans[i]='G';
                }
                else
                {
                    ka=0;
                    if(b>0)
                    {
                        ++kb;
                        --b;
                        ans[i]='B';
                    }
                }
            }
        }
        else
        {
            if(ans[i-1]=='B' || i==1)
            {
                if(kb<k && b>0)
                {
                    ++kb;
                    --b;
                    ans[i]='B';
                }
                else
                {
                    ka=0;
                    kb=0;
                    if(a>0)
                    {
                        ++ka;
                        --a;
                        ans[i]='G';
                    }
                }
            }
            else
            {
                kb=0;
                if(kb<k && b>0)
                {
                    ++kb;
                    --b;
                    ans[i]='B';
                }
                else
                {
                    ka=0;
                    kb=0;
                    if(a>0)
                    {
                        ++ka;
                        --a;
                        ans[i]='G';
                    }
                }
            }
        }
        if(ans[i]!='B' && ans[i]!='G')
        {
            cout<<"NO";
            return 0;
        }
    }
    for(i=1; i<=n; ++i)
        cout<<ans[i];
}
