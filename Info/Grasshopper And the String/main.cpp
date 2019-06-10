#include <iostream>
#include <cstring>

using namespace std;

bool vocala(char c)
{
    if(c=='A' || c=='O' || c=='E' || c=='I' || c=='U' || c=='Y')
        return 1;
    return 0;
}

int main()
{
    int last=-1;
    char s[200];
    cin>>s;
    int mn=0;
    int n=strlen(s);
    for(int i=0; i<n; ++i)
        if(vocala(s[i]))
        {
            mn=max(mn,i-last);
            last=i;
        }
    mn=max(mn,n-last);
    cout<<mn;
}
