#include <iostream>
#include <fstream>
#include <deque>

using namespace std;

ifstream fin("permuta.in");
ofstream fout("permuta.out");

#define nmax 100100
#define pb push_back
#define pf push_front

deque <int> ans;
int v[nmax];
int n,i;

int main()
{
    fin>>n;
    for(i=n; i>0; --i)
        fin>>v[i];
    for(i=1; i<=n; ++i)
    {
        if(ans.size())
        {
            ans.pf(ans.back());
            ans.pop_back();
        }
        ans.pf(v[i]);
    }
    for(auto it:ans)
        fout<<it<<' ';
}
