#include <iostream>
#include <fstream>
#include <cstring>
#include <stack>
#include <cmath>

using namespace std;

ifstream fin("evaluare2.in");
ofstream fout("evaluare2.out");

#define ll long long

char s[110];
long long i,n;

ll oglindit(ll x)
{
    ll ans = 0;
    while(x>0)
    {
        ans=ans*10 + x%10;
        x/=10;
    }
    return ans;
}

ll eval_sum();

ll eval_nr()
{
    if(s[i]=='(')
    {
        ++i;
        ll ans = eval_sum();
        ++i;
        return ans;
    }
    else
    {
        long long ok = 0;
        while(s[i]=='!')
        {
            ++i;
            ++ok;
        }
        long long ans = 0;
        if(s[i]<='9' && s[i]>='0')
        {
            while(i<n && s[i]<='9' && s[i]>='0')
            {
                ans = s[i]-'0' + ans *10;
                ++i;
            }
        }
        else
        {
            ++i;
            ans = eval_sum();
            ++i;
        }
        if(ok%2==1)
            return oglindit(ans);
        if(ok%2==0 && ok>0)
            return oglindit(oglindit(ans));
        return ans;
    }
}

ll eval_pow()
{
    stack <ll> q;
    q.push(eval_nr());
    while(i<n && s[i]=='^')
    {
        ++i;
        q.push(eval_nr());
    }
    ll a = q.top();
    q.pop();
    while(!q.empty())
    {
        a = pow(q.top(),a);
        q.pop();
    }
    return a;
}

ll eval_div()
{
    ll a = eval_pow();
    while(i<n && s[i]=='/')
    {
        ++i;
        a /= eval_pow();
    }
    return a;
}

ll eval_sum()
{
    ll a = eval_div();
    while(i<n && s[i]=='+')
    {
        ++i;
        a += eval_div();
    }
    return a;
}

int main()
{
    fin>>s;
    n = strlen(s);
    fout<<eval_sum();
}
