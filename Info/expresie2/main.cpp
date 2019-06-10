#include <iostream>
#include <fstream>
#include <algorithm>
#include <cstring>

using namespace std;

ifstream fin("expresie2.in");
ofstream fout("expresie2.out");

char s[100100];
int i,n;

int number()
{
    int ans=1;
    if(s[i]=='-')
        ans=-1,++i;
    if(s[i+1]<='9' && s[i+1]>='0')
    {
        ans=ans*(s[i]-'0')*10+ans*(s[i+1]-'0');
        i+=2;
    }
    else
    {
        ans=ans*(s[i]-'0');
        ++i;
    }
    return ans;
}

int nth();

int sum_max()
{
    int ans=-1e9,curr=0;
    int ok=1;
    while(i<n && s[i]!=')')
    {
        switch(s[i])
        {
        case '(':
            ++i;
            curr+=sum_max();
            ++i;
            break;
        case '[':
            ++i;
            curr+=nth();
            ++i;
            break;
        case ',':
            ++i;
            ok=0;
            break;
        default:
            if(s[i]!='-' && (s[i]>'9' || s[i]<'0'))
            {
                ++i;
                break;
            }
            curr+=number();
            break;
        }
        if(ok)
        {
            ans=max(ans,curr);
            if(curr<0)
                curr=0;
        }
        ok=1;
    }
    return ans;
}

int nth()
{
    vector <int> w;
    while(i<n && s[i]!=']')
    {
        switch(s[i])
        {
        case '(':
            ++i;
            w.push_back(sum_max());
            ++i;
            break;
        case '[':
            ++i;
            w.push_back(nth());
            ++i;
            break;
        case ',':
            ++i;
            break;
        default:
            if(s[i]!='-' && (s[i]>'9' || s[i]<'0'))
            {
                ++i;
                break;
            }
            w.push_back(number());
            break;
        }
    }
    nth_element(w.begin(),w.begin()+(w.size()-1)/2,w.end());
    return w[(w.size()-1)/2];
}

int sum()
{
    int ans=0;
    while(i<n)
    {
        switch(s[i])
        {
        case ',':
            ++i;
            break;
        case '(':
            ++i;
            ans+=sum_max();
            ++i;
            break;
        case '[':
            ++i;
            ans+=nth();
            ++i;
            break;
        default:
            if(s[i]!='-' && (s[i]>'9' || s[i]<'0'))
            {
                ++i;
                break;
            }
            ans+=number();
            break;
        }
    }
    return ans;
}

int main()
{
    fin.getline(s,100100);
    n = strlen(s);
    int ans=0;
    for(i=0; i<n; ++i)
    {
        if(s[i]<='9' && s[i]>='0')
        {
            ++ans;
            if(s[i+1]<='9' && s[i+1]>='0')
                --ans;
        }
    }
    fout<<ans<<'\n';
    i=0;
    fout<<sum();
}
