#include <iostream>

using namespace std;

long long a,b,c;

long long v[10],mn,j,i;

int  main()
    {
    cin>>v[1]>>v[2]>>v[3];
    mn=max(v[1],max(v[2],v[3]));
    mn*=2;

    for(i=1; i<=3; ++i)
        for(j=1; j<=3; ++j)
            {
            long long a = v[1];
            long long b = v[2];
            long long c = v[3];

            if(i==2)
                {
                --b;
                --c;
                }
            else if(i==3)
                --c;

            if(j==2)
                {
                --a;
                }
            else if(j==3)
                {
                --a;
                --b;
                }

            if(a>=b && a>=c)
                mn=min(mn, (a+a-b-c));
            else
                {
                if(b>=a && b>=c)
                    mn=min(mn, (b+b-a-c));
                else
                    mn=min(mn, (c+c-a-b));
                }
            }
    cout<<mn;
    }
