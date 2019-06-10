#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second

ifstream fin("beep.in");
ofstream fout("beep.out");

string a,b;

bool is_here(int x)
{
    int lim = min(b.length(),a.length()+x);
    for(int i=x; i<lim; ++i)
        if(a[i-x]!=b[i])
            return false;
    if((x==0 || b[x-1]==' ') && (x+a.length()==b.length() || b[x+a.length()]==' '))
        return true;
    return false;
}

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    getline(fin,a);
    getline(fin,b);
    for(int i=0; i<b.length(); ++i)
    {
        if(is_here(i))
            fout<<"beep ",i+=a.length();
        else
            fout<<b[i];
    }
}
