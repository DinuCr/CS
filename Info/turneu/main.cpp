#include <iostream>
#include <deque>
using namespace std;
int m[110][110],i,j,a,n,b;
deque <int> v;
int w[110];
int main()
{
    cin>>n;
    cin>>a>>b;
    m[a][b]=1;
    v.push_back(a);
    v.push_back(b);
    w[a]=w[b]=1;
    for(i=1; i<n*(n-1)/2; i++)
    {
        cin>>a>>b;
        m[a][b]=1;
    }
    for(i=1; i<=n; i++)
        if(!w[i])
        {
            if(m[i][v.front()]==1)
                v.push_front(i);
            else if(m[v.back()][i]==1)
                v.push_back(i);
            else
                for(j=0; j<v.size()-1; j++)
                    if(m[v[j]][i]==1 && m[i][v[j+1]]==1)
                    {
                        v.insert(v.begin()+j+1,i);
                        break;
                    }
            w[i]=1;
        }
    for(i=0; i<n; i++)
        cout<<v[i]<<' ';
}

