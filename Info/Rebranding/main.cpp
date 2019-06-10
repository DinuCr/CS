#include <iostream>
using namespace std;
int n,m,i;
char s[200010],c1,c2,v[30],c3,c4;
int main()
{
    cin>>n>>m;
    for(i=0;i<n;i++)
    cin>>s[i];
    for(i='a';i<='z';i++)
        v[i-'a']=i;
    for(i=1;i<=m;i++)
    {
        cin>>c1>>c2;
            c3=c2;
            c4=c1;
            while(v[c3-'a']!=c2)
                c3=v[c3-'a'];
            while(v[c4-'a']!=c1)
                c4=v[c4-'a'];
            v[c4-'a']=c2;
            v[c3-'a']=c1;
    }
    for(i=0;i<n;i++)
    s[i]=v[s[i]-'a'];
    for(i=0;i<n;i++)
    cout<<s[i];
}
