#include <iostream>
#include <fstream>
#include <stack>
#include <utility>

using namespace std;

ifstream fin("acces2.in");
ofstream fout("acces2.out");

#define nmax 1010
#define mp make_pair
#define f first
#define s second

stack <pair <int,pair<int,int> > >q;
int v[nmax][nmax];
int ndd,avb,nr,i,j,n,m,x,y,k;

void fill1(short x,short y)
{
    if(v[x][y]!=0)
    {
        if(v[x][y]==-2)
            ++nr;
        v[x][y]=0;
        fill1(x+1,y);
        fill1(x,y+1);
        fill1(x,y-1);
        fill1(x-1,y);
    }
}

int main()
{
    fin>>n>>m;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        {
            char c;
            fin>>c;
            if(c=='-')
                v[i][j]=-1;
            if(c=='P')
                v[i][j]=-2;
            if(c=='#')
                v[i][j]=0;
        }
    avb=0;
    ndd=0;
    for(i=1; i<=n; ++i)
        for(j=1; j<=m; ++j)
        if(v[i][j]<0)
        {
            nr=0;

            if(nr==0)
            {
                q.push(mp(i,mp(j,0)));
                while(!q.empty())
                {
                    x = q.top().f;
                    y = q.top().s.f;
                    k = q.top().s.s;
                    if((v[x][y]==0 && k==0) || k==4)
                        q.pop();
                    else
                    {
                        if(v[x][y]==-2)
                            ++nr;
                        v[x][y]=0;
                        switch(k)
                        {
                        case 0:
                            ++q.top().s.s;
                            q.push(mp(x+1,mp(y,0)));
                            break;
                        case 1:
                            ++q.top().s.s;
                            q.push(mp(x-1,mp(y,0)));
                            break;
                        case 2:
                            ++q.top().s.s;
                            q.push(mp(x,mp(y+1,0)));
                            break;
                        case 3:
                            ++q.top().s.s;
                            q.push(mp(x,mp(y-1,0)));
                            break;
                        }
                    }
                }
            }


            if(nr>1)
                avb+=nr-1;
            if(nr==0)
                ndd++;
        }

    if(ndd<=avb)
        fout<<ndd;
    else
        fout<<((ndd-avb)*2+avb);
}
