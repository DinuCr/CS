#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <int> v[1010];
vector <int> w;
int n,i,j,ok,s,nr,x;
int main()
{
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>x;
        w.push_back(x);
    }
    sort(w.begin(),w.end());
    for(i=0;i<n;i++)
    {
        ok=0;
        for(j=1;j<=nr;j++)
        if(w[i]>v[j].back())
        {
            v[j].push_back(w[i]);
            ok=1;
            break;
        }
        if(!ok)
            v[++nr].push_back(w[i]);
    }
    for(i=1;i<=nr;i++)
        s+=v[i].size()-1;
    cout<<s;
}
