#include <iostream>
#include <stack>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("depou.in");
ofstream fout("depou.out");

#define mp make_pair
#define f first
#define s second

int v[1010];
int c[1010];
stack <int> q;
vector <pair<char,char> > ans;
int i,n,k;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    for(i=n; i>0; --i)
    {
        if(v[i]==c[k]+1)
        {
            ans.push_back(mp('A','C'));
            c[++k]=v[i];
        }
        else
        {
            q.push(v[i]);
            ans.push_back(mp('A','B'));
        }
        while(!q.empty() && q.top()==c[k]+1)
        {
            q.pop();
            c[++k]=c[k-1]+1;
            ans.push_back(mp('B','C'));
        }
    }
    if(!q.empty())
        cout<<'0';
    else
    {
        cout<<ans.size()<<'\n';
        for(i=0; i<ans.size(); ++i)
            cout<<ans[i].f<<' '<<ans[i].s<<'\n';
    }
}
