#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
FILE *f=fopen("casa.in","r");
FILE *g=fopen("casa.out","w");
int p,n,m;
struct nod
{
    int x,y,nr;
};
struct nod2
{
    int x,y;
};
inline bool limit(int x,int y)
{
    if(x<0 || x>=n || y>=m || y<0)
    return 0;
    return 1;
}
bool compare(nod2 x,nod2 y)
{
    if(x.x!=y.x)
    return x.x<y.x;
    return x.y<y.y;
}
bool bs(nod2 v[],int ls,int ld,int x,int y)
{
    if(ls>=ld)
    {
        if(v[ls].x!=x || v[ls].y!=y)
        return 0;
        return 1;
    }
    else
    {
        if(v[(ls+ld)/2].x>x)
        return bs(v,ls,(ls+ld)/2-1,x,y);
        else
        if(v[(ls+ld)/2].x<x)
        return bs(v,(ls+ld)/2+1,ld,x,y);
        else
        if(v[(ls+ld)/2].y>y)
        return bs(v,ls,(ls+ld)/2-1,x,y);
        else
        if(v[(ls+ld)/2].y<y)
        return bs(v,(ls+ld)/2+1,ld,x,y);
        else
        return 1;
    }
}
#define fs fscanf
#define fp fprintf
int main()
{
    fs(f,"%d",&p);
    if(p==2)
    {
        int nr=0,i,j,x,y=10000000,k,dx[4]={0,-1,1,0},dy[4]={1,0,0,-1};
        fs(f,"%ld%ld",&n,&m);
        int v[n+1][m+1];
        for(i=0;i<n;++i)
        for(j=0;j<m;++j)
        {
            fs(f,"%ld",&v[i][j]);
            nr+=v[i][j];
            if(v[i][j])
            if(y>j && i==0)
            {
                y=j;
                x=0;
            }
        }
        queue <nod> c;
        nod q;
        q.x=x;
        q.y=y;
        q.nr=1;
        c.push(q);
        v[x][y]=0;
        fp(g,"%ld %ld\n",nr,y+1);
        nr=1;
        while(c.size())
        {
            for(k=0;k<4;++k)
            if(limit(c.front().x+dx[k],c.front().y+dy[k]) && v[c.front().x+dx[k]][c.front().y+dy[k]])
            {
                v[c.front().x+dx[k]][c.front().y+dy[k]]=0;
                q.x=c.front().x+dx[k];
                q.y=c.front().y+dy[k];
                q.nr=nr+1;
                nr++;
                c.push(q);
                switch(k)
                {
                case 0:
                    fp(g,"%ld E\n",c.front().nr);
                    break;
                case 1:
                    fp(g,"%ld N\n",c.front().nr);
                    break;
                case 2:
                    fp(g,"%ld S\n",c.front().nr);
                    break;
                case 3:
                    fp(g,"%ld V\n",c.front().nr);
                    break;
                }
            }
            c.pop();

        }
    }
    else
    {
        int nr,i,x,n=0,m=0,j,n0=0,m0=0;
        char c;
        fs(f,"%ld",&nr);
        nod2 v[nr+2];
        v[1].x=v[1].y=0;
        for(i=2;i<=nr;++i)
        {
            fs(f,"%ld %c",&x,&c);
            v[i]=v[x];
            switch(c)
            {
            case 'E':
                v[i].y++;
                break;
            case 'S':
                v[i].x++;
                break;
            case 'V':
                v[i].y--;
                break;
            case 'N':
                v[i].x--;
                break;
            }
            n0=min(n0,v[i].x);
            m0=min(m0,v[i].y);
            n=max(n,v[i].x);
            m=max(m,v[i].y);
        }
        fp(g,"%ld %ld\n",n-n0+1,m-m0+1);
        sort(v+1,v+nr+1,compare);
        for(i=n0;i<=n;i++)
        {
        for(j=m0;j<=m;j++)
        if(bs(v,1,nr,i,j))
        fp(g,"1 ");
        else
        fp(g,"0 ");
        fp(g,"\n");
        }
    }
}
