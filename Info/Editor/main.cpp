#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("editor.in");
ofstream fout("editor.out");

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    int t;
    fin>>t;
    while(t--)
    {
        string a;
        string s;
        fin>>a;
        stack <char> q;
        a.pop_back();
        for(int i=0; i<a.length(); ++i)
            if(a[i]=='*')
            {
                if(s.length())
                s.pop_back();
            }
            else
                s+=a[i];
        for(int i=0; i<s.length(); ++i)
        {
            if(s[i]=='*')
            {
                if(!q.empty())
                    q.pop();
            }
            else
            if(s[i]=='(' || s[i]=='[')
               q.push(s[i]);
            else
            if(!q.empty() && ((s[i]==')' && q.top()=='(') || (s[i]==']' && q.top()=='[')))
                q.pop();
            else
                q.push('x');
        }
        if(q.empty())
            fout<<":)\n";
        else
            fout<<":(\n";
    }
}
