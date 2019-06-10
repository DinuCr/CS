#include <iostream>

using namespace std;

char c;
int v[30],i,j,n,nr,ok,k;

int main()
{
    cin>>n;
    if(n>26)
        cout<<-1;
    else
    {
        for(i=1; i<=n; ++i)
        {
            cin>>c;
            v[c-'a']++;
        }
        for(i=0; i<26; ++i)
            if(v[i]>1)
            nr+=v[i]-1;
        cout<<nr;
    }
}
