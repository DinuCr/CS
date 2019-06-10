#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("subsecvente2.in");
ofstream fout("subsecvente2.out");


struct nod
{
    int x;
    nod *a,*b;
    nod ()
    {
        this->x=0;
        this->a = NULL;
        this->b = NULL;
    }
};

nod *rad;
char s[50010];
int i,n,curr,cnt;

void build(int z)
{
    int n = strlen(s);
    for(int i=0; i<n; ++i)
    {
        nod *p = rad;
        for(int j=0; j<60; ++j)
        {
            p->x|=z;
            if(i+j==n)
                break;
            if(s[i+j]=='a')
            {
                if(p->a==NULL)
                {
                    nod *q = new nod;
                    p->a = q;
                    p = q;
                }
                else
                    p = p->a;
            }
            else
            {
                if(p->b==NULL)
                {
                    nod *q = new nod;
                    p->b = q;
                    p = q;
                }
                else
                    p = p->b;
            }
        }
    }
}

int check()
{
    int n = strlen(s);
    for(int i=0; i<n; ++i)
    {
        nod *p = rad;
        int j;
        for(j=0; j<60; ++j)
        {
            if(i+j==n)
                break;
            if(s[i+j]=='a')
            {
                if(p->a==NULL || p->a->x!=cnt)
                {
                    curr=max(curr,j);
                    break;
                }
                else
                    p = p->a;
            }
            else
            {
                if(p->b==NULL || p->b->x!=cnt)
                {
                    curr=max(curr,j);
                    break;
                }
                else
                    p = p->b;
            }
        }
        if(j==60 || i+j==n)
        {
            curr=max(curr,min(60,n-i));
        }
    }
    return curr;
}

int main()
{
    fin>>n;
    cnt = (1<<n)-1;
    fin>>s;
    rad = new nod;
    build(1);
    int ans = 61;
    for(i=1; i<n; ++i)
    {
        fin>>s;
        build(1<<i);
    }
    fout<<check();
}
