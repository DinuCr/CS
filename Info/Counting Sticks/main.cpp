#include <iostream>
#include <cstring>

using namespace std;

char s[1000];
int ok,a,b,c,n,i;

int main()
{
    cin>>s;
    n=strlen(s);
    for(i=0; i<n; ++i)
        switch(ok)
        {
        case 0:
        {
            if(s[i]=='|')
                ++a;
            else
                ok=1;
            break;
        }
        case 1:
        {
            if(s[i]=='|')
                ++b;
            else
                ok=2;
            break;
        }
        case 2:
        {
            ++c;
            break;
        }
        }
    if(a+b==c)
        cout<<s;
    else
    {
        if(c-1==a+b+1 && c>1)
        {
            for(i=1; i<=a; ++i)
                cout<<'|';
            cout<<'+';
            for(i=1; i<=b+1; ++i)
                cout<<'|';
            cout<<'=';
            for(i=1; i<c; ++i)
                cout<<'|';
        }
        else if(a+b-1==c+1 && (a>1 || b>1))
        {
            if(b>1)
            {
                for(i=1; i<=a; ++i)
                    cout<<'|';
                cout<<'+';
                for(i=1; i<b; ++i)
                    cout<<'|';
                cout<<'=';
                for(i=1; i<=c+1; ++i)
                    cout<<'|';
            }
            else if(a>1)

            {
                for(i=1; i<a; ++i)
                    cout<<'|';
                cout<<'+';
                for(i=1; i<=b; ++i)
                    cout<<'|';
                cout<<'=';
                for(i=1; i<=c+1; ++i)
                    cout<<'|';
            }

        }
        else
            cout<<"Impossible";
    }
}
