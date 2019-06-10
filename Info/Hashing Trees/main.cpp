#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define nmax (int) 1e5+10

int h[nmax];
int n;
vector <int> a;
vector <int> b;

void build_answer()
{
    int r,l,i,j;
    r=l=0;
    for(i=0; i<=n; ++i)
    {
        for(j=1; j<=h[i]; ++j)
            a.push_back(l),b.push_back(j%2==0?l:r);
        l=r+1;
        r=r+h[i];
    }
}

int main()
{
    int i;
    cin>>n;
    int ok=1;
    for(i=0; i<=n; ++i)
    {
        cin>>h[i];
        if(h[i]>=2 && h[i-1]>=2)
            ok=0;
    }
    if(ok)
        cout<<"perfect";
    else
    {
        build_answer();
        cout<<"ambiguous\n";
        for(auto it:a)
            cout<<it<<' ';
        cout<<'\n';
        for(auto it:b)
            cout<<it<<' ';
    }
}
