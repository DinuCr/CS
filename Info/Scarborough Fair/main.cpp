#include <iostream>

using namespace std;

int main()
{
    int i,n,m;
    string s;
    cin>>n>>m;
    cin>>s;
    while(m--)
    {
        int a,b;
        char c,d;
        cin>>a>>b>>c>>d;
        for(i=a-1; i<b; ++i)
            if(s[i]==c)
                s[i]=d;
    }
    cout<<s;
}
