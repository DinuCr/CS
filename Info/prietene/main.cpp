#include <iostream>
#include <fstream>
#include <cstring>
#include <unordered_set>

using namespace std;

#define ll long long

long long p[65];
int ad[155][155];
ll ad2[155][3];
unordered_set <int> v[155];
ll x[3];
ll y[3];
int upd[155];
ll mx;

inline void add(int a,int b)
{
    ++ad[a][b];
    if(ad[a][b]==1)
    {
        ad2[a][(b-1)/60]|=p[(b-1)%60];
        v[a].insert(b);
    }
}

inline void del(int a,int b)
{
    --ad[a][b];
    if(!ad[a][b])
    {
        ad2[a][(b-1)/60]^=p[(b-1)%60];
        v[a].erase(b);
    }
}

#define DIM 10000
char buff[DIM];
int poz=0;

void citeste(int &numar)
{
    numar = 0;
    while (buff[poz] < '0' || buff[poz] > '9')
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    while ('0'<=buff[poz] && buff[poz]<='9')
    {
        numar = numar*10 + buff[poz] - '0';
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    }
}

void citeste2(char &c)
{
    while (buff[poz] < 'a' || buff[poz] > 'z')
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    if ('a'<=buff[poz] && buff[poz]<='z')
    {
        c = buff[poz];
        if (++poz == DIM)
            fread(buff,1,DIM,stdin),poz=0;
    }
}


inline bool check(int a,int b)
{
    x[0]=ad2[a][0];
    x[1]=ad2[a][1];
    x[2]=ad2[a][2];

    y[0]=ad2[b][0];
    y[1]=ad2[b][1];
    y[2]=ad2[b][2];
    for(auto it:v[a])
    {
        x[0]|=ad2[it][0];
        x[1]|=ad2[it][1];
        x[2]|=ad2[it][2];
    }
    for(auto it:v[b])
    {
        y[0]|=ad2[it][0];
        y[1]|=ad2[it][1];
        y[2]|=ad2[it][2];
    }
    x[(a-1)/60]&=mx-p[(a-1)%60];
    x[(b-1)/60]&=mx-p[(b-1)%60];
    y[(a-1)/60]&=mx-p[(a-1)%60];
    y[(b-1)/60]&=mx-p[(b-1)%60];
    return (x[0]==y[0] && x[1]==y[1] && x[2]==y[2]);
}

int main()
{
    freopen("prietene.in","r",stdin);
    freopen("prietene.out","w",stdout);
    int i;
    p[0]=1;
    for(i=1; i<64; ++i)
        p[i]=p[i-1]<<1;
    mx = (1ll<<61)-1;
    int t;
    citeste(t);
    while(t--)
    {
        int n,m,q;
        memset(ad, 0, sizeof(ad));
        memset(ad2, 0, sizeof(ad2));
        citeste(n);
        citeste(m);
        int a,b;
        char c;
        while(m--)
        {
            citeste(a);
            citeste(b);
            add(a,b);
        }
        citeste(q);
        while(q--)
        {
            citeste2(c);
            citeste(a);
            citeste(b);
            switch(c)
            {
            case 'q':
                if(check(a,b))
                    printf("YES\n");
                else
                    printf("NO\n");
                break;
            case 'a':
                add(a,b);
                break;
            case 'd':
                del(a,b);
                break;
            }
        }
    }
}
