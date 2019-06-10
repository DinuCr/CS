#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("emm.in");
ofstream fout("emm.out");

#define nmax 100010

char s[nmax];
int i,n;

int eval();

int termen()
{
    int curr = 0;
    if(s[i]=='(')
    {
        ++i;
        curr = eval();
        ++i;
        return curr;
    }
    while(i<n && s[i]<='9' && s[i]>='0')
    {
        curr=curr*10+s[i]-'0';
        ++i;
    }
    return curr;
}

int eval()
{
    int curr = termen();
    while(i<n && (s[i]=='m' || s[i]=='M'))
    {
        if(s[i]=='m')
        {
            ++i;
            curr=min(curr,termen());
        }
        else
        {
            ++i;
            curr=max(curr,termen());
        }
    }
    return curr;
}

int main()
{
    fin>>s;
    n = strlen(s);
    fout<<eval();
}
