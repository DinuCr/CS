#include <iostream>

using namespace std;
struct coord
{
    int x,y;
};
int nr,p,a,b;
coord v[4];
int main()
{
    cin>>v[1].x>>v[1].y>>v[2].x>>v[2].y>>v[3].x>>v[3].y;
    for(int i=1;i<3;i++)
    for(int j=i+1;j<=3;j++)
    {
        if(v[i].x==v[j].x || v[i].y==v[j].y)
        nr++,p=6-i-j;
    }
    if(nr==3)
        cout<<1;
    else
    if(nr==2)
        cout<<2;
    else
    if(nr==1)
    {
        if(p==3)
            a=1,b=2;
        if(p==2)
            a=1,b=3;
        if(p==1)
            a=2,b=3;
        if(v[a].x==v[b].x)
        {
            if(v[p].y<max(v[a].y,v[b].y) && v[p].y>min(v[a].y,v[b].y))
                cout<<3;
            else
                cout<<2;
        }

        if(v[a].y==v[b].y)
        {
            if(v[p].x<max(v[a].x,v[b].x) && v[p].x>min(v[a].x,v[b].x))
                cout<<3;
            else
                cout<<2;
        }
    }
    else
        cout<<3;
}
