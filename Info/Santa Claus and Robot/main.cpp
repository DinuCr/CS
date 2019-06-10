#include <iostream>

using namespace std;

int viz[300],i;
char v[201000];

char next(char c)
{
    switch(c)
    {
    case 'R':
        return 'L';
    case 'L':
        return 'R';
    case 'U':
        return 'D';
    case 'D':
        return 'U';
    }
}

int n;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    int cnt = 0;
    for(i=1; i<=n; ++i)
    {
        if(viz[next(v[i])])
        {
            cnt++;
            viz['R']=viz['L']=viz['U']=viz['D']=0;
        }
        viz[v[i]]=1;
    }
    cout<<cnt+1;
}
