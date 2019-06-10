#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("piese2.in");
ofstream fout("piese2.out");

int last,curr,sum,n,i,k;

int main()
{
    int t;
    fin>>t>>n>>k;
    while(t--)
    {
        sum=0;
        for(i=1; i<=k; ++i)
        {
            fin>>last>>curr;
            sum+=curr-last+1;
        }
        if(sum%2==1)
            fout<<"Miruna\n";
        else
            fout<<"Aglaia\n";
    }
}
