#include<iostream>
using namespace std;
typedef struct vector
{
    int x,y;
};
vector a,b,v;
vector suma(vector a,vector b)
{
    vector w;
    w.x=a.x+b.x;
    w.y=a.y+b.y;
    return w;
}
int main()
{
    cin>>a.x>>a.y>>b.x>>b.y;
    v=suma(a,b);
    cout<<v.x<<' '<<v.y;
    return 0;
}
