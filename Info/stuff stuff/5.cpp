#include <iostream>
#include <cstdio>
#include <fstream>
using namespace std;
int v[100],x,i;
ifstream f("5.txt");
int main()
{
    while(f>>x)
        v[x]++;
    for(i=10;i<100;i++)
    while(v[i]>0)
    {
        cout<<i<<' ';
        v[i]--;
    }
}
