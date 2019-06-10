#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

char ans[55][15];
int v[55];
char s[10];
int n,k,i,j,p;

int main()
{
    cin>>n>>k;
    for(i=k; i<=n; ++i)
    {
        cin>>s;
        if(s[0]=='N')
            v[i]=0;
        else
            v[i]=1;
    }
    for(i=0; i<10; ++i)
        ans[n][i]='a'+i;
    p=n-1;
    for(i=n; i>=k; --i)
    {
        if(v[i]==0)
        {
            strcpy(ans[p],ans[p+1]);
            --p;
        }
        else
        {
            for( ;p>i-k; --p)
            {
                strcpy(ans[p],ans[p+1]);
                next_permutation(ans[p],ans[p]+10);
            }
        }
    }
    while(p>0)
    {
        strcpy(ans[p],ans[p+1]);
        next_permutation(ans[p],ans[p]+10);
        --p;
    }
    for(i=1; i<=n; ++i)
    {
        cout<<(char)(ans[i][0]+'A'-'a');
        for(j=1; j<10; ++j)
            cout<<ans[i][j];
        cout<<' ';
    }
}
