#include <iostream>
#include <fstream>

using namespace std;

int d[20111],i,n,j,s,e,c;

int main()
{
    ifstream f("energii.in");
    ofstream g("energii.out");

    f>>n>>s;

    for(i=1; i<=s; ++i)
        d[i]=-1;

    for(i=1; i<=n; ++i)
    {
        f>>e>>c;

        for(j=s; j>=0; --j)
        if(d[j]!=-1 || j==0)
        {
            if(j+e<=s)
            {
                if(d[j+e]==-1 || d[j+e]>d[j]+c)
                    d[j+e]=d[j]+c;
            }
            else
            {
                if(d[s]==-1 || d[s]>d[j]+c)
                    d[s]=d[j]+c;
            }
        }
    }
    g<<d[s];
}
