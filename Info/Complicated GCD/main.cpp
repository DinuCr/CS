#include <iostream>
#include <cstring>

using namespace std;

char s1[1000],s2[1000];
int ok,i,n1,n2;

int main()
{
    cin>>s1;
    cin>>s2;
    n1=strlen(s1);
    n2=strlen(s2);
    if(n1==n2)
    {
        ok=1;
        for(i=0; i<=n1 && ok; ++i)
            if(s1[i]!=s2[i])
                ok=0;
        if(ok)
        {
            cout<<s1;
            return 0;
        }
    }
    cout<<1;
}
