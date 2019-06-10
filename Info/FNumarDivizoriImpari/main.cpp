#include <iostream>

using namespace std;

#include <cmath>

void  nr_div_imp(int n,int &s)
{
    s=0;
    int k = sqrt(n) + 1;
    for(int i=1; i<k; ++i)
        if(n - n/i*i == 0)
        {
            if((i & 1) == 1)
                ++s;
            if((n / i) & 1 == 1)
                ++s;
        }
    if((k - 1) * (k - 1) == n && ((k - 1) & 1) == 1)
        --s;
}

int main()
{
    int n,s;
    cin>>n;
    nr_div_imp(n,s);
    cout<<s;
}
