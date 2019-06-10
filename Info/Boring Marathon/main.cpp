#include <iostream>
#include <cstring>
#include <iomanip>

using namespace std;

char s[100100];
int v[30];
int t;

int main()
{
    cin>>t;
    while(t--)
    {
        memset(v,0,sizeof(v));
        cin>>s;
        double ans = 0;
        double n = strlen(s);
        for(int i=0; i<n; ++i)
            ++v[s[i]-'A'];
        for(int i=0; i<='Z'-'A'; ++i)
            ans += (double)(1LL*v[i]*v[i])/n;
        cout<<setprecision(6)<<fixed<<ans<<'\n';
    }
}
