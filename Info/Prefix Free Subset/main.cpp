#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef struct node
{
    bool x = 0;
    node * v[26];
    node ()
    {
        for(int i=0; i<26; ++i)
            v[i]=NULL;
    }
};

#define nmax (int)1e6+10

node *root;
vector <string> v;
int w[nmax];
string s;

inline bool cmp(const int &a,const int &b)
{
    return v[a].size()<v[b].size();
}

inline bool existent(node *&root,int &p,int curr)
{
    if(root->x)
        return true;
    if(root->v[s[curr]] == NULL)
        return false;
    return existent(root->v[s[curr]],p,curr+1);
}

void add(node *&root,int &p,int curr)
{
    if(curr == s.size())
    {
        root->x=1;
        return ;
    }
    else
    root->x = 0;
    if(root->v[s[curr]] == NULL)
    {
        node *q = new node;
        root->v[s[curr]]=q;
        add(q,p,curr+1);
    }
    add(root->v[s[curr]],p,curr+1);
}

int main()
{
    int n,k,i;
    cin>>n>>k;
    for(i=0; i<n; ++i)
    {
        cin>>s;
        for(int j=0; j<s.size(); ++j)
            s[j]-='a';
        v.push_back(s);
        w[i]=i;
    }
    sort(w,w+n,cmp);
    int curr = 0,ans = 0;
    root = new node;
    for(int j=0; j<v.size(); ++j)
    {
        s = v[w[j]];
        i = w[j];
        if(!existent(root,i,0))
            add(root,i,0),++curr;
        else
            add(root,i,0);
        if(curr == k)
        {
            cout<<v[w[j]].size();
            return 0;
        }
    }
    cout<<-1;
}
