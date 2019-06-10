#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define nmax 100100
#define f first
#define s second
#define mp make_pair

vector<pair<int,int> > v1;
vector<pair<int,int> > v2;

bool cmp(pair<int,int> a,pair<int,int> b)
{
    if(a.f!=b.f)
    {
        return a.f<b.f;
    }
    return a.s>b.s;
}

int aint1[nmax*2];
int aint2[nmax*2];

void build_v1()
{
    int i;
    for(i=v1.size(); i<v1.size()*2; ++i)
        aint1[i]=v1[i-v1.size()].s;
    for(i=v1.size()-1; i>0; --i)
        aint1[i]=max(aint1[i<<1],aint1[i<<1|1]);
}


void build_v2()
{
    int i;
    for(i=v2.size(); i<v2.size()*2; ++i)
        aint2[i]=v2[i-v2.size()].s;
    for(i=v2.size()-1; i>0; --i)
        aint2[i]=max(aint2[i<<1],aint2[i<<1|1]);
}

int query1(int a,int b)
{
    int ans = 0;
    for(a+=v1.size(),b+=v1.size(); a<b; a>>=1,b>>=1)
    {
        if(a&1)
            ans = max(ans,aint1[a++]);
        if(b&1)
            ans = max(ans,aint1[--b]);
    }
    return ans;
}

int query2(int a,int b)
{
    int ans = 0;
    for(a+=v2.size(),b+=v2.size(); a<b; a>>=1,b>>=1)
    {
        if(a&1)
            ans = max(ans,aint2[a++]);
        if(b&1)
            ans = max(ans,aint2[--b]);
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(false);
    int n,s1,s2,i;
    cin>>n>>s1>>s2;
    for(i=1; i<=n; ++i)
    {
        int a,b;
        char c;
        cin>>a>>b>>c;
        if(c=='C')
            v1.push_back(mp(b,a));///s = beauty, f = cost
        else
            v2.push_back(mp(b,a));
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);

    build_v1();
    build_v2();

    int max1 = 0 ;
    int max2 = 0 ;
    int ans = 0;
    for(auto it:v1)
        if(s1>=it.f)
            max1=max(max1,it.s);

    for(auto it:v2)
        if(s2>=it.f)
            max2=max(max2,it.s);
    if(max1 && max2)
        ans = max1+max2;

    int cnt = -1;
    for(auto it:v1)
    if(s1>it.f)
    {
        ++cnt;
        int curr = -1,step;
        for(step = 1; step<nmax; step<<=1);
        for( ; step; step>>=1)
            if(curr+step<v1.size() && v1[curr+step].f<=s1-it.f)
                curr+=step;
        int curr2 = max(query1(0,min(curr+1,cnt)),query1(max(curr+1,cnt),curr+1));
        if(curr2>0)
            ans = max(ans,it.s+curr2);
    }
    cnt = -1;
    for(auto it:v2)
    if(s2>it.f)
    {
        ++cnt;
        int curr = -1,step;
        for(step = 1; step<nmax; step<<=1);
        for( ; step; step>>=1)
            if(curr+step<v2.size() && v2[curr+step].f<=s2-it.f)
                curr+=step;
        int curr2 = max(query2(0,min(curr+1,cnt)),query2(max(curr+1,cnt),curr+1));
        if(curr2>0)
            ans = max(ans,it.s+curr2);
    }
    cout<<ans;
}
