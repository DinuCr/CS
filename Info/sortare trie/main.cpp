#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;

ifstream fin("algsort.in");
ofstream fout("algsort.out");

string s;

struct vertex
{
    int x;
    vertex *v[10];
    vertex()
    {
        this->x=0;
        for(int i=0; i<10; ++i)
            this->v[i]=NULL;
    }
};

vertex *root[11];

void add(vertex *&root,int curr,int x)
{
    if(x<s.length())
    {
        cout<<s[x]<<' ';
        if(root->v[s[x]-'0']==NULL)
        {
            vertex *q = new vertex;
            root->v[s[x]-'0']=q;
            add(q,curr,x+1);
        }
        else
        add(root->v[s[x]-'0'],curr,x+1);
    }
    else
    ++root->x;
}

void compute(vertex *&root,int curr)
{
    for(int i=0; i<root->x; ++i)
        fout<<curr<<' ';
    for(int i=0; i<10; ++i)
        if(root->v[i]!=NULL)
            compute(root->v[i],curr*10+i);
}

int main()
{
    int n;
    for(int i=0; i<11; ++i)
        root[i]=new vertex;
    fin>>n;
    for(int i=1; i<=n; ++i)
    {
        fin>>s;
        cout<<s<<'\n';
        add(root[s.length()],i,0);
    }
    for(int i=1; i<11; ++i)
        compute(root[i],0);
}
