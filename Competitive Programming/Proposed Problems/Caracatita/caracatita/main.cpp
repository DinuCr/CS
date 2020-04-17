#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("9-caracatita.in");
ofstream fout("9-caracatita.out");

vector <vector <pair<char, int> > > v; /// vector siruri vrednice
int in[505]; /// 1 daca sirul x este in trie, 0 altfel
vector <int> w;

typedef struct Node
{
    char val;
    map <int, int> v;
    Node *next[26];
    Node()
    {
        val = 0;
        for(int i=0; i<26; ++i)
           next[i]=nullptr;
    }
};

Node *root = new Node();

void add(Node *&root, string &s, int pos, int k)
{
    if(s.length() == k)
        return ;

    if(root->next[s[k]-'a']==nullptr)
    {
        Node *q = new Node;
        root->next[s[k]-'a']=q;
        q->val = s[k];
        q->v[pos]++;
    }
    else
    {
        root->next[s[k]-'a']->v[pos]++;
    }

    add(root->next[s[k]-'a'], s, pos, k+1);
}

int query(Node *&root, string &s, int k)
{
    if(s.length() == k)
    {
        int ans = 0;

        for(auto it:w)
            ans += root->v[it];

        return ans;
    }
    if(root->next[s[k]-'a']==nullptr)
        return 0;
    return query(root->next[s[k]-'a'], s, k+1);
}

void add_suffix(string s, int pos)
{
    while(!s.empty())
    {
        add(root, s, pos, 0);
        s.erase(s.begin());
    }
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    int n,m;

    fin>>n;
    for(int i=1; i<=n; ++i)
    {
        string curr;
        fin>>curr;

        vector <pair<char, int> >s;
        char last = 0;
        for(auto it:curr)
            if(it!=last)
                s.pb(mp(it,1)),last=it;
            else
                s.back().s++;

        v.pb(s);
    }

    fin>>m;
    int abc = 0;
    while(m--)
    {
        abc ++;
        string curr;
        fin>>curr;

        vector <int> cnt;
        string s;
        char last = 0;

        for(auto it:curr)
            if(it!=last)
                s.pb(it),cnt.pb(1),last=it;
            else
                cnt.back()++;

        w.clear(); /// stringurile ce indeplinesc prima regula

        for(int i=0; i<v.size(); ++i)
        {
            int ok = 1;
            int a = 0;
            int b = 0;
            int current = cnt[a];
            while(a < s.size() && b < v[i].size())
            {
                if(s[a]==v[i][b].f)
                {
                    current-=v[i][b].s;
                    if(current<=0)
                    {
                        ++a;
                        if(a<s.size())
                            current = cnt[a];
                    }
                }
                ++b;
            }
            if(a==s.size())
            {
                w.pb(i);
                if(!in[i])
                {
                    string x;
                    for(auto it:v[i])
                        x.pb(it.f);
                    add_suffix(x, i), in[i] = 1;
                }
            }
        }

        fout<<query(root, s, 0)<<'\n';
    }

}
