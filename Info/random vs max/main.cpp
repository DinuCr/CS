#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;
#define n 10000000
int v[n],w[n],i,mx;
int main()
{
    srand(time(NULL));
    for(i=0;i<n;++i)
    {
        v[i]=i;
        w[i]=rand()%n;
    }
    clock_t timer;
    timer=clock();
    for(i=0;i<n;++i)
    mx=max(mx,v[i]);
    cout<<(clock()-timer)/(double)1000<<'\n';
    timer=clock();
    for(i=0;i<n;++i)
    mx=max(mx,w[i]);
    cout<<(clock()-timer)/(double)1000;
}
