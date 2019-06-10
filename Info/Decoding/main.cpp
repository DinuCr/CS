#include <iostream>
#include <deque>

using namespace std;

deque <char > q;
int n,i;
char c;

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        cin>>c;
        if((i+n)%2==1)
            q.push_front(c);
        else
            q.push_back(c);
    }
    for(auto it:q)
        cout<<it;
}
