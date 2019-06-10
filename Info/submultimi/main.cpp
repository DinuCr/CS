#include <cstdio>

using namespace std;

int i,j,n;

int main()
{
    freopen("submultimi.in","r",stdin);
    freopen("submultimi.out","w",stdout);
    scanf("%d",&n);
    int ld=1<<n;
    for(i=1; i<ld; ++i)
    {
        for(j=0; j<n; ++j)
        {
            if( ((1<<j) & i )!=0)
                printf("%d ",j+1);
        }
        printf("\n");
    }
}
