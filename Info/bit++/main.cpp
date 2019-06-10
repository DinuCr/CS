#include<iostream>
using namespace std;
int n,i,pl,nr,k;
char s[3];
int main()
{
    cin>>n;
    for(k=1;k<=n;k++)
    {
        cin>>s;
        pl=0;
        for(i=0;i<=2;i++)
        {
            if(s[i]=='+')
                pl++;
        }
        if(pl>1)
            nr++;
        else
            nr--;
    }
    cout<<nr;
}
