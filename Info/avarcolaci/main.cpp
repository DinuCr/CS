#include <iostream>
#include <deque>
#include <fstream>
using namespace std;
int n,k,v[5000010];
long long s;
int i;
ifstream f("deque.in");
ofstream g("deque.out");
deque<int> w;
int main()
{
    f>>n>>k;
    for(i=1;i<=n;i++)
        f>>v[i];
    for(i=1;i<=n;i++)
    {
        while(!w.empty() && v[w.back()]>v[i])
            w.pop_back();
        w.push_back(i);
        if(w.front()==i-k)
            w.pop_front();
        if(i>=k)
            s+=v[w.front()];
    }
    g<<s;
}
