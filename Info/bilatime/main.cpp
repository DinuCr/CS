#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

ifstream fin("bilatime.in");
ofstream fout("bilatime.out");

#define nmax 100010

int n = 1;
vector <int> v[nmax];
int ans[nmax];

void df_create(int x)
{
    int val;
    int nr_fii = 2;
    while(nr_fii>0 && fin>>val)
    {
        --nr_fii;
        if(val==0)
            continue;
        ++n;
        ans[n]=val;
        v[x].push_back(n);
        df_create(n);
    }
}

int main()
{
    fin>>ans[1];

    df_create(1);
    queue<int> q;
    q.push(1);
    while(!q.empty())
    {
        int nod = q.front();
        fout<<ans[nod]<<' ';
        q.pop();
        for(int i=0; i<v[nod].size(); ++i)
            q.push(v[nod][i]);
    }
}
