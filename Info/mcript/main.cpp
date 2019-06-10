#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("mcript.in");
ofstream fout("mcript.out");

struct nod
{
    bool ok;
    nod *v[9];
    nod()
    {
        this->ok=0;
        for(int i=0; i<9; ++i)
            this->v[i]=NULL;
    }
};

nod *rad;
int n,q,i,p,ok;
char s[15];
int v[15],j;

void add(nod *&rad,int k)
{
    if(k==p)
    {
        rad->ok=1;
        return;
    }
    else
    {
        if(rad->v[s[k]-'0'-1]==NULL)
        {
            nod *q = new nod();
            rad->v[s[k]-'0'-1]=q;
            add(q,k+1);
        }
        else
            add(rad->v[s[k]-'0'-1],k+1);
    }
}

bool verif()
{
    nod *q =rad;
    for(int i=0; i<p; ++i)
    {
        if(q->v[s[i]]==NULL)
            return 0;
        q=q->v[s[i]];
    }
    return q->ok;
}

int main()
{
    fin>>n;
    for(i=1; i<=n; ++i)
    {
        char c;
        fin>>c;
        v[i]=c-'0';
    }
    fin>>n;
    rad = new nod();
    for(i=1; i<=n; ++i)
    {
        fin>>s;
        p = strlen(s);
        add(rad,0);
    }
    int q;
    fin>>q;
    char da[3] = "1\n";
    char nu[3] = "0\n";
    while(q--)
    {
        fin>>n;
        int ok=1;
        for(i=1; i<=n; ++i)
        {
            fin>>s;
            p = strlen(s);
            if(ok)
            {

                for(j=0; j<p; ++j)
                    s[j]=v[s[j]-'0']-1;
                ok=verif();
            }
        }
        if(ok)
        {
            fout<<da;
            continue;
        }
        fout<<nu;
    }
}
