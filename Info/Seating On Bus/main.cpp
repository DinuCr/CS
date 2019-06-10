#include <iostream>

using namespace std;
int v[110][5],n,m,nr=1;;
int main()
{
    int i,j;
    cin>>n>>m;
    while(m)
    {
        for(i=1; i<=n; ++i)
        {
            if(m)
            {
                v[i][1]=nr;
                ++nr;
                --m;
            }
            if(m)
            {
                v[i][4]=nr;
                ++nr;
                --m;
            }
        }
        for(i=1; i<=n; ++i)
        {
            if(m)
            {
                v[i][2]=nr;
                ++nr;
                --m;
            }
            if(m)
            {
                v[i][3]=nr;
                ++nr;
                --m;
            }
        }
    }
    for(i=1; i<=n && (v[i][1]+v[i][2]+v[i][3]+v[i][4]!=0); ++i)
    {
        if(v[i][2])
            cout<<v[i][2]<<' ';
        if(v[i][1])
            cout<<v[i][1]<<' ';

        if(v[i][3])
            cout<<v[i][3]<<' ';
        if(v[i][4])
            cout<<v[i][4]<<' ';
    }
}
