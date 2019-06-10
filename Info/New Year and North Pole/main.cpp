#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    int cord = 0;
    int n,i;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int a;
        char s[10];
        cin>>a>>s;
        switch(s[0])
        {
        case 'E':
            if(cord==0 || cord==20000)
            {
                cout<<"NO";
                return 0;
            }
            break;
        case 'W':
            if(cord==0 || cord==20000)
            {
                cout<<"NO";
                return 0;
            }
            break;
        case 'N':
            cord-=a;
            if(cord<0)
            {
                cout<<"NO";
                return 0;
            }
            break;
        case 'S':
            cord+=a;
            if(cord>20000)
            {
                cout<<"NO";
                return 0;
            }
            break;
        }
    }
    if(!cord)
        cout<<"YES";
    else
        cout<<"NO";
}
