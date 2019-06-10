#include <iostream>
#include <stack>

using namespace std;

template <class foo>
class stiva
{
public:
    stack <foo> s;

    void add(foo x)
    {
        s.push(x);
    }
    void del()
    {
        s.pop();
    }
    foo top()
    {
        return s.top();
    }
};

class obiect
{
    public:
    int a,b,c;
    obiect()
    {
        cin>>a>>b>>c;
    }
};

int main()
{
    int n,x;
    stiva <obiect> v;
    obiect a,b;
    v.add(a);
    v.add(b);
    cout<<v.top().a<<' ';
    stiva <int> w;
    w.add(2);
    cout<<w.top();
}
