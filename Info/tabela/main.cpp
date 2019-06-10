#include <iostream>
#include <fstream>

using namespace std;

ifstream f("tabela.in");
ofstream g("tabela.out");

int i,j;

int main()
{
    f>>i>>j;
    int x=(i-1)^(j-1);
    g<<x;
}
