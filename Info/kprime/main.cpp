#include <iostream>
#include <fstream>
#include <cmath>
#include <deque>

using namespace std;

ifstream fin("kprime.in");
ofstream fout("kprime.out");

bool prim(int x)
{
    int k = sqrt(x);
    if(x<2)
        return 0;
    for(int i=2; i<=k; ++i)
        if(x%i==0)
            return 0;
    return 1;
}

int v[100100];
deque <int> q;
int n,k,i,curr;
long long ans;

int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
        fin>>v[i];
    int last=0;
    for(i=1; i<=n; ++i)
    {
        if(prim(v[i]))
        {
            ++curr;
            q.push_back(i);
        }
        if(curr==k)
            ans+=q.front()-last;
        else
        if(curr>k)
        {
            --curr;
            last=q.front();
            q.pop_front();
            ans+=q.front()-last;
        }
    }
    fout<<ans;
}
