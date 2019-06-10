#include <fstream>

using namespace std;

ifstream fin("ksecv3.in");
ofstream fout("ksecv3.out");

long long n,k,sum,curr,i,x;
int main()
{
    fin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        sum+=x;
    }
    if(sum%k!=0)
    {
        fout<<-1;
        return 0;
    }
    sum/=k;
    ifstream fin("ksecv3.in");
    fin>>n>>k;
    for(i=1; i<=n; ++i)
    {
        fin>>x;
        curr+=x;
        if(curr==sum)
            curr=0;
        if(curr>sum)
        {
            fout<<-1;
            return 0;
        }
    }
    curr = 0;
    ifstream fin1("ksecv3.in");
    fin1>>n>>k;
    for(i=1; i<=n; ++i)
    {
        fin1>>x;
        curr+=x;
        if(curr==sum)
            curr=0,fout<<i<<' ';
    }
}
