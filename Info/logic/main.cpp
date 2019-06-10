#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("logic.in");
ofstream fout("logic.out");

char a[505];
char b[505];
int lit[100];
char dif[10]="diferite\n";
char egal[10]="egale\n";
int q;
int val[100];
int poz[100];
int i,n,m;

int eval_b_or();

int termen_b()
{
    if(b[i]=='~')
    {
        ++i;
        return !termen_b();
    }
    if(b[i]=='(')
    {
        ++i;
        int ans = eval_b_or();
        ++i;
        return ans;
    }
    return val[b[i++]-'a'];
}

int eval_b_and()
{
    int ans = termen_b();
    while(i<m && b[i]=='&')
    {
        ++i;
        ans&=termen_b();
    }
    return ans;
}

int eval_b_xor()
{
    int ans = eval_b_and();
    while(i<m && b[i]=='^')
    {
        ++i;
        ans^=eval_b_and();
    }
    return ans;
}

int eval_b_or()
{
    int ans = eval_b_xor();
    while(i<m && b[i]=='|')
    {
        ++i;
        ans|=eval_b_xor();
    }
    return ans;
}

int eval_a_or();

int termen_a()
{
    if(a[i]=='~')
    {
        ++i;
        return !termen_a();
    }
    if(a[i]=='(')
    {
        ++i;
        int ans = eval_a_or();
        ++i;
        return ans;
    }
    return val[a[i++]-'a'];
}


int eval_a_and()
{
    int ans = termen_a();
    while(i<n && a[i]=='&')
    {
        ++i;
        ans&=termen_a();
    }
    return ans;
}

int eval_a_xor()
{
    int ans = eval_a_and();
    while(i<n && a[i]=='^')
    {
        ++i;
        ans^=eval_a_and();
    }
    return ans;
}

int eval_a_or()
{
    int ans = eval_a_xor();
    while(i<n && a[i]=='|')
    {
        ++i;
        ans|=eval_a_xor();
    }
    return ans;
}

int main()
{
    fin>>q;
    while(q--)
    {
        fin>>a;
        fin>>b;
        n = strlen(a);
        m = strlen(b);

        memset(lit, 0, sizeof(lit));

        for(i=0; i<n; ++i)
            if(a[i]<='z' && a[i]>='a')
            {
                lit[a[i]-'a']=1;
            }
        int ok=0;
        for(i=0; i<m; ++i)
            if(b[i]<='z' && b[i]>='a')
            {
                if(lit[b[i]-'a']==1)
                    lit[b[i]-'a']=2;
                else
                if(lit[b[i]-'a']!=2)
                    lit[b[i]-'a']=-1;
            }
        int k = 0;
        for(i=0; i<='z'-'a'; ++i)
            if(lit[i]==2)
            {
                poz[++k]=i;
            }
            else
            if(lit[i]!=0)
            {
                ok=1;
                break;
            }
        if(ok)
        {
            fout<<dif;
            continue;
        }

        int lim = (1<<k);
        int vala,valb;
        for(int bkt=0; bkt<lim; ++bkt)
        {
            for(i=1; i<=k; ++i)
                val[poz[i]]=(((1<<(i-1)) & bkt)>0);
            i=0;
            vala = eval_a_or();
            i=0;
            valb = eval_b_or();
            if(vala!=valb)
            {
                ok=1;
                break;
            }
        }
        if(ok)
            fout<<dif;
        else
            fout<<egal;
    }
}
