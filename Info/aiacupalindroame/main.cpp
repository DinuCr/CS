#include <fstream>
#include <cstring>
#include <vector>

using namespace std;

ifstream fin("aiacupalindroame.in");
ofstream fout("aiacupalindroame.out");

#define nmax 100010

struct nod
{
    int ok;
    nod *v[26];
    nod()
    {
        this->ok = 0;
        for(int i=0; i<26; ++i)
            this->v[i]=NULL;
    }
};

nod *rad;
vector <int> v[nmax];
int poz[nmax];
char s[nmax];

void df(nod *&curr,int x,int t)
{
    poz[x]=curr->ok;
    for(auto it:v[x])
        if(it!=t)
        {
            if(curr->v[s[it]-'a']!=NULL)
                df(curr->v[s[it]-'a'],it,x);
            else
            {
                nod *p = new nod;
                p->ok=it;
                curr->v[s[it]-'a']=p;
                df(p,it,x);
            }
        }
}

int main()
{
    int n,q,i,t;
    fin>>n>>q;
    for(i=2; i<=n; ++i)
    {
        fin>>t;
        v[t].push_back(i);
    }
    fin>>s+2;
    rad = new nod;
    rad->ok=1;
    df(rad,1,0);
    int a,b;
    while(q--)
    {
        fin>>a>>b;
        fout<<(poz[a]==poz[b])<<'\n';
    }
}
