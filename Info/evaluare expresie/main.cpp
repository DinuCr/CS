#include <iostream>
#include <cstring>

using namespace std;

char s[1000];
int i,n;

int eval();

int number()
{
    int ans = 0;
    if(s[i]=='(')
    {
        ++i;
        ans = eval();
        ++i;
        return ans;
    }
    while(s[i]<='9' && s[i]>='0')
    {
        ans = ans*10+s[i]-'0';
        ++i;
    }
    return ans;
}

int termen()
{
    int ans = number();
    while(i<n && (s[i]=='*' || s[i]=='/'))
    {
        if(s[i++]=='*')
            ans*=number();
        else
            ans/=number();
    }
    return ans;
}

int eval()
{
    int ans = termen();
    while(i<n && (s[i]=='-' || s[i]=='+'))
    {
        if(s[i++]=='-')
            ans-=termen();
        else
            ans+=termen();
    }
    return ans;
}

int main()
{
    cin>>s;
    n = strlen(s);
    cout<<eval();
}
