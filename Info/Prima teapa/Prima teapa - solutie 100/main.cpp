#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ifstream fin("primateapa.in");
ofstream fout("primateapa.out");

int main()
{
    fin.sync_with_stdio(false);
    fout.sync_with_stdio(false);

    string s;
    getline(fin,s);
    for(int i=0,j=0; i<s.length(); ++i)
        if(s[i]<='Z' && s[i]>='A')
        {
            if(j&1)
                fout<<(char)(s[i]+(s[0]+s[s.length()-1]-2*'A'+2));
            else
                fout<<(char)(s[i]-(s[0]+s[s.length()-1]-2*'A'+2));
            ++j;
        }
        else
            fout<<'\n';

}
