#include <iostream>
#include <cstring>

using namespace std;

char s[200];
int i,last,nr;

int nex(char a,char b)
{
    int mn=30;
    if(a<b)
    {
        mn=b-a;
        mn=min(mn,'z'-b+a-'a'+1);
    }
    else
    {
        mn=a-b;
        mn=min(mn,'z'-a+b-'a'+1);
    }
    return mn;
}

int main()
{
    cin>>s;
    int n=strlen(s);
    last='a';
    for(i=0; i<n; ++i)
    {
        nr+=nex(last,s[i]);
        last=s[i];
    }
    cout<<nr;
}
