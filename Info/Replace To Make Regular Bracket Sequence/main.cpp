#include <iostream>
#include <cstring>
#include <stack>
using namespace std;
stack <char> v;
int d(char x)
{
    if(x=='(' || x=='[' || x=='{' || x=='<')
        return 1;
    return -1;
}
bool same(char a , char b)
{
    if (a == '<' && b == '>') return 1;
    if (a == '(' && b == ')') return 1;
    if (a == '[' && b == ']') return 1;
    if (a == '{' && b == '}') return 1;
    return 0;
}
int S,i,n,ok,nr;
char s[1000100];
int main()
{
    cin.getline(s,1000010);
    n=strlen(s);
    S=0;
    for(i=0;i<n;i++)
    {
        S+=d(s[i]);
        if(S<0)
        {
            cout<<"Impossible";
            ok=1;
            break;
        }
        if(d(s[i])>0)
            v.push(s[i]);
        else
        {
            if(!same(v.top() , s[i]))
                nr++;//,cout<<v.top()<<' '<<s[i]<<'\n';
            v.pop();
        }

    }
    if (v.size())
    {
        cout<<"Impossible";
        ok=1;
    }
    if(!ok)
        cout<<nr;
}
