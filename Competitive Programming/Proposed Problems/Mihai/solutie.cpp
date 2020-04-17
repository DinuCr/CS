//check check check
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<queue>
#include<cstring>
#include<map>
#include<iomanip>
#include<set>

#define ll long long
#define pb(x) push_back(x)

using namespace std;

typedef pair<int,int> ii;

const int NMAX = 0;

ifstream fin("9-mihai.in");
ofstream fout("9-mihai.ok");

int main()
{
    ll Q,N,i,j;

    fin>>Q;

    for(i = 1 ; i <= Q ; ++i)
    {
        ll N,M;
        fin>>N>>M;
        if(N % 2 == 1 || M % 2 == 1)
            fout<<"1\n";
        else
            fout<<"0\n";
    }

    return 0;
}
