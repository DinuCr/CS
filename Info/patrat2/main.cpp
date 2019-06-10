#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

ifstream fin("patrat2.in");
ofstream fout("patrat2.out");

int n;

int main()
{
    fin>>n;
    while(n)
    {
        fout<<(int)sqrt(n)<<'\n';
        n-=(int)sqrt(n)*(int)sqrt(n);
    }
}
