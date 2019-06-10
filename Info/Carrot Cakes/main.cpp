#include <iostream>

using namespace std;

int main()
{
    int n,t,k,d;
    cin>>n>>t>>k>>d;
    int a = ((n-1)/k + 1) * t;
    int b = 0;
    int cnt = 1;
    int ok=0,t1=0,t2=0;
    while(n>0)
    {
        if(t1<t2)
        {
            n-=k;
            t1+=t;
        }
        else
        {
            if(!ok)
            {
                t2+=d;
                ok=1;
            }
            else
            {
                t2+=t;
                n-=k;
            }
        }
    }
    b = max(t1,t2);
    if(a<=b)
        cout<<"NO";
    else
        cout<<"YES";
}
