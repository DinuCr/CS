#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("random.in");
ofstream fout("random.out");

int main()
{
    int n;
    fin>>n;
    if(n==1982)
        fout<<"Robert Tarjan";
    else
    if(n==1986)
        fout<<"Leslie Valiant";
    else
    if(n==1990)
        fout<<"Alexander Razborov";
    else
    if(n==1994)
        fout<<"Avi Wigderson";
    else
    if(n==1998)
        fout<<"Peter Shor";
    else
    if(n==2002)
        fout<<"Madhu Sudan";
    else
    if(n==2006)
        fout<<"Jon Kleinberg";
    else
    if(n==2010)
        fout<<"Daniel Spielman";
    else
        fout<<"Subhash Khot";
}
