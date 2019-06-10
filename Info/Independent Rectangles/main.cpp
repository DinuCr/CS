#include <iostream>
#include <algorithm>

using namespace std;

#define nmax 100100

typedef struct dr
{
    int a,b;
};

bool compare(dr a, dr b)
{
    if(a.a==b.a)
        return a.b<b.b;
    return a.a<b.a;
}

dr v[nmax],last,last2;
int n,i,nr;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>v[i].a>>v[i].b;
    }
    sort(v+1,v+n+1,compare);
    nr=n;
    for(i=n; i>0; --i)
    {
        if(v[i].a!=v[i+1].a)
            if(v[i].b>last.b)
            {
                last2=last;
                last=v[i];
            }
        if((v[i].a<last2.a && v[i].b<last2.b) || (v[i].a<last.a && v[i].b<last.b))
            --nr;
    }
    cout<<nr;
}
