#include <iostream>
#include <fstream>
#include <deque>
using namespace std;

ifstream fin("zen.in");
ofstream fout("zen.out");

#define mp make_pair
#define f first
#define s second

deque <pair<long long,int> > q;
long long n,k,i,x;

int main()
{
    fin>>n>>k;
    q.push_back(mp(0,0));
    for(i=1; i<=n; ++i)
    {
        fin>>x;

        while(q.size() && q.front().s<i-k)
            q.pop_front();
        x+=q.front().f;
        while(q.size() && q.back().f>=x)
            q.pop_back();
        q.push_back(mp(x,i));
    }
    fout<<x;
}
