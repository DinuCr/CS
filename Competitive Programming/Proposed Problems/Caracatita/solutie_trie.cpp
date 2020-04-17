#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("8-caracatita.in");
ofstream fout("8-caracatita.ok");

vector <string> v; /// vector siruri vrednice
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

int query(Node *&root, string s, int k)
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

        string s;
        char last = 0;
        for(auto it:curr)
            if(it!=last)
                s.pb(it),last=it;

        v.pb(s);
    }

    fin>>m;
    while(m--)
    {
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
            int curr = cnt[a];
            while(a < s.length() && b < v[i].length())
            {
                if(s[a]==v[i][b])
                {
                    curr-=b+1;
                    if(curr<=0)
                    {
                        ++a;
                        curr = cnt[a];
                    }
                }
                ++b;
            }
            if(a==s.length())
            {
                w.pb(i);
                if(!in[i])
                    add_suffix(v[i], i), in[i] = 1;
            }
        }

        fout<<query(root, s, 0)<<'\n';
    }

}

/*

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

void add(Node *&root, string &s, int k, int start)
{
    if(s.length() == k)
        return ;

    if(root->next[s[k]-'a']==nullptr)
    {
        Node *q = new Node;
        root->next[s[k]-'a']=q;
        q->val = s[k];
        q->v[start+k+1]++;
    }
    else
    {
        root->next[s[k]-'a']->v[start+k+1]++;
    }

    add(root->next[s[k]-'a'], s, k+1, start);
}

int query(Node *&root, string s, int mx, int k)
{
    if(s.length() == k)
    {
        int ans = 0;
        for(auto it:root->v)
            if(it.f>=mx)
            {
                ans+=it.s;
            }
        return ans;
    }
    if(root->next[s[k]-'a']==nullptr)
        return 0;
    return query(root->next[s[k]-'a'], s, mx, k+1);
}

int main()
{
	fin.sync_with_stdio(false);
	fout.sync_with_stdio(false);

	Node *root = new Node();

	int n,m;

    cin>>n;
    for(int i=1; i<=n; ++i)
    {
        string curr;
        cin>>curr;

        string s;
        int last = 0;
        for(auto it:curr)
            if(it!=last)
            {
                s.pb(it);
                last = it;
            }
        int start = 0;
        while(!s.empty())
        {
            add(root, s, 0, start);
            s.erase(s.begin());
            start++;
        }
    }
    cin>>m;
    while(m--)
    {
        string s;
        cin>>s;
        vector <pair<char, int> > v;
        v.pb(mp(s[0],1));
        for(int i=1; i<s.length(); ++i)
            if(s[i]==v[v.size()-1].f)
                v[v.size()-1].s++;
            else
                v.pb(mp(s[i],1));

        for(int i=1; i<v.size(); ++i)
            v[i].s = max(v[i-1].s + 1, max(v[i].s, i+1));

        string curr;
        for(auto it:v)
            curr.pb(it.f);

        cout<<query(root, curr, v[v.size()-1].s, 0)<<'\n';
    }
}
*/
