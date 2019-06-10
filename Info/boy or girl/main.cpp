#include <iostream>
#include<cstring>
using namespace std;
int v[35],i,nr;
char s[101];
int main()
{
    cin>>s;
    for(i=0;i<strlen(s);i++)
    {
        if(v[s[i]-'a']==0)
        {
            nr++;
            v[s[i]-'a']++;
        }
    }
    if(nr%2==1)
        cout<<"IGNORE HIM!";
    else
        cout<<"CHAT WITH HER!";
    return 0;
}
