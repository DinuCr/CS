#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

ifstream fin("trandafiri.in");
ofstream fout("trandafiri.out");

vector <int> v;

int main()
{
    int n;
    fin>>n;
    for(int i=1; i<=n; ++i)
    {
        int x;
        fin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    long long ans = 0;
    for(int i=n-1; i>0; --i)
    {
        ans += v[i]-v[i-1]+1;
    }
    fout<<ans;

}
