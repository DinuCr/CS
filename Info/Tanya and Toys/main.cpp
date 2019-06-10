#include <iostream>
#include <algorithm>
using namespace std;
int n,m,i,a[100001];
int h,pc,q,juc[100001];
int main()
{
    cin>>n>>m;
    for(i=1; i<=n; i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    h=1;
    while(pc<m)
    {
        pc++;
        if(pc==a[h])h++;
        else
        {
            m-=pc;
            juc[++q]=pc;
        }
    }
    cout<<q<<'\n';
    for(i=1; i<=q; i++)
        cout<<juc[i]<<" ";
    return 0;
}
