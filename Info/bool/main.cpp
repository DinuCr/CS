#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("bool.in");
ofstream fout("bool.out");

char buff[1100];
char s[1100];
char change[110];
int val[30];
int i,n;

int eval_or();

int eval_fact()
{
    //fact
    if(s[i]=='(')
    {
        ++i;
        int ans = eval_or();
        ++i;
        return ans;
    }
    else
    {
        if(s[i]==1)
        {
            ++i;
            return 1;
        }
        if(s[i]==0)
        {
            ++i;
            return 0;
        }
        return val[s[i++]-'A'];
    }
}

int eval_not()
{
    //not
    if(s[i]=='!')
    {
        ++i;
        return !eval_not();
    }
    return eval_fact();
}

int eval_and()
{
    //and
    int ans = eval_not();
    while(i<n && s[i]=='&')
    {
        ++i;
        ans &= eval_not();
    }
    return ans;
}

int eval_or()
{
    //or
    int ans = eval_and();
    while(i<n && s[i]=='|')
    {
        ++i;
        ans |= eval_and();
    }
    return ans;
}

int main()
{
    fin.getline(buff,1010);
    n = strlen(buff);
    int m=0;
    for(i=0; i<n; ++i)
    {
        if(buff[i]=='T' && buff[i+1]=='R')
        {
            s[m++]=1;
            i+=3;
            continue;
        }
        if(buff[i]=='F' && buff[i+1]=='A')
        {
            s[m++]=0;
            i+=4;
            continue;
        }
        if(buff[i]=='N' && buff[i+1]=='O')
        {
            s[m++]='!';
            i+=2;
            continue;
        }
        if(buff[i]=='A' && buff[i+1]=='N')
        {
            s[m++]='&';
            i+=2;
            continue;
        }
        if(buff[i]=='O' && buff[i+1]=='R')
        {
            s[m++]='|';
            ++i;
            continue;
        }
        if(buff[i]!=' ')
            s[m++]=buff[i];
    }

    n=m;
    fin>>m;
    while(m--)
    {
        char c;
        fin>>c;
        val[c-'A']^=1;
        i=0;
        fout<<eval_or();
    }
}
