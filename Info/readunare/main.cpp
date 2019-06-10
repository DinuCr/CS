#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

ifstream fin("readunare.in");
ofstream fout("readunare.out");

char s[4500];
string d[600];
int nr[600];
int a,b,ans,n,i;

int process()
{
    --n;
    int ans = 0,cnt = 0;
    for(int i=1; i<n; ++i)
    {
        if(s[i]=='{')
            ++cnt;
        else
        if(s[i]=='}')
        {
            --cnt;
            if(!cnt)
                ++ans;
        }
    }
    return ans;
}

int main()
{
    fin>>s;
    n = strlen(s);
    a = process();
    fin>>s;
    n = strlen(s);
    b = process();
    ans = a+b;

    d[0]="{}";

    for(i=1; i<=ans; ++i)
    {
        d[i].push_back('{');

        for(int j=i-1; j>=0; --j)
        {
            d[i].insert(d[i].size(),d[j]);
            if(j>0)
                d[i].push_back(',');
        }
        d[i].push_back('}');
    }
    fout<<d[ans];
}
