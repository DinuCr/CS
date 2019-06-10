#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

char s[1010];
int n,i,j,m1[11],m2[11],ok;

int main()
{
    cin>>n;
    char c;
    cin>>s;
    for(i=1; i<=n; ++i)
    {
        cin>>c;
        m1[c-'0']++;
        m2[c-'0']++;
    }

    int ans = 0;
    for(i=0; i<n; ++i)
    {
        ok = 0;
        for(j=s[i]-'0'; j<=9; ++j)
            if(m1[j]>0)
            {
                m1[j]--;
                ok=1;
                break;
            }
        if(!ok)
        {
        for(j=0; j<=9; ++j)
            if(m1[j]>0)
            {
                m1[j]--;
                ++ans;
                break;
            }
        }
    }
    cout<<ans<<'\n';
    ans=0;
    for(i=0; i<n; ++i)
    {
        ok = 0;
        for(j=s[i]-'0'+1; j<=9; ++j)
            if(m2[j]>0)
            {
                m2[j]--;
                ok=1;
                ++ans;
                break;
            }
        if(!ok)
        {
        for(j=0; j<=9; ++j)
            if(m2[j]>0)
            {
                m2[j]--;
                break;
            }
        }
    }
    cout<<ans;
}
