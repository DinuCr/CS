#include <iostream>
#include <vector>
using namespace std;
vector <int> v[100100];
int i,i2,p2,p5,m,z;
int main()
{
    for(i=1;i<=1000000;i++)
    if(z<100001)
    {
        i2=i;
        while(i2%2==0)
            p2++,i2/=2;
        while(i2%5==0)
            p5++,i2/=5;
        z+=min(p2,p5);
        if(p2<p5)
            p5-=p2,p2=0;
        else
            p2-=p5,p5=0;
        v[z].push_back(i);
    }
    cin>>m;
    cout<<v[m].size()<<'\n';
    if(v[m].size())
    {
        for(i=0;i<v[m].size();i++)
            cout<<v[m][i]<<' ';
    }
}
