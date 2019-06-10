#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

char v[1100000][15];
int w[1100000];
int n,s,k,i,x;

priority_queue <int, vector<int>, greater<int> > heap;

int main()
{
    cin>>n;
    s=0;
    char sir[15];
    for(i=1; i<=n; ++i)
    {
        cin>>sir;
        switch(sir[0])
        {
        case 'i':
            cin>>x;
            w[k+1]=x;
            heap.push(x);
            break;
        case 'g':
            cin>>x;
            if(heap.size() && heap.top()==x)
            {
                w[k+1]=x;
                break;
            }
            while(heap.size()>0 &&
                  heap.top()<x)
            {
                ++k;
                strcpy(v[k],"removeMin");
                heap.pop();
            }
            if(heap.size()==0 || heap.top()!=x)
            {
                ++k;
                strcpy(v[k],"insert");
                w[k]=x;
                heap.push(x);
            }
            w[k+1]=x;
            break;
        case 'r':
            if(heap.size()==0)
            {
                ++k;
                strcpy(v[k],"insert");
                w[k]=1;
                heap.push(1);
            }
            heap.pop();
            break;
        }
        ++k;
        strcpy(v[k],sir);
    }
    cout<<k<<'\n';
    for(i=1; i<=k; ++i)
    {
        if(v[i][0]=='r')
            cout<<v[i]<<'\n';
        else
            cout<<v[i]<<' '<<w[i]<<'\n';
    }
}
