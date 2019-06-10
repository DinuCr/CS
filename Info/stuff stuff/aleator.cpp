#include<iostream>
#include<fstream>
#include<time.h>
#include<stdlib.h>
using namespace std;
ofstream g("subsir.in");
int i;
int main()
{
    srand(time(NULL));
    g<<"100\n";
    for(i=1;i<=100;i++)
        g<<rand()%3000<<' ';
    g.close();
    return 0;
}
