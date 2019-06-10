#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

long long n,b,g,mx;

struct nod
{
    long long b,g;
};

nod v[310000];

priority_queue <long long, vector <long long>, greater <long long> > h;

bool cmp(const nod &a,const nod &b)
{
    return a.b>b.b;
}

void possible()
{
    int i;
    long long curr=1,poz=n+1;
    for(i=1; i<n; ++i)
        if(v[i].b>b)
        {
            ++curr;
            h.push(v[i].g-v[i].b);
        }
        else
        {
            poz=i;
            break;
        }
    mx=curr;
    while(b>=0 && curr> 1)
    {
        mx=min(mx,curr);
        if(!h.empty())
        {
            b-=h.top()+1;
            --curr;
            h.pop();
        }
        else
        {
            mx=1;
        }
        while(v[poz].b>b && poz<n)
        {
            h.push(v[poz].g-v[poz].b);
            ++poz;
            ++curr;
        }
    }
    if(curr==1 && b>=0)
        mx=1;
}


int main()
{
    int i;
    cin>>n;
    cin>>b>>g;
    for(i=1; i<n; ++i)
    {
        cin>>v[i].b>>v[i].g;
    }
    sort(v+1,v+n,cmp);
    possible();
    cout<<mx;
}
