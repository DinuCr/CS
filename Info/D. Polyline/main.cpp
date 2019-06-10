#include <iostream>

using namespace std;
struct coord
{
    int x,y;
};
int nr;
coord v[4];
int main()
{
    cin>>v[1].x>>v[1].y>>v[2].x>>v[2].y>>v[3].x>>v[3].y;
    for(int i=1;i<3;i++)
    for(int j=i+1;j<=3;j++)
    {
        if(v[i].x==v[j].x || v[i].y==v[j].y)
            nr++;
    }
    if(nr==3)
        cout<<1;
    else
    if(nr==2)
        cout<<2;
    else
        cout<<3;
}
