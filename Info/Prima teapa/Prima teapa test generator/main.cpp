#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ofstream fin("9-primateapa.in");
ofstream fout("9-primateapa.ok");

int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    string s;

    srand(time(NULL));

    for(int i=1; i<=1e6; ++i)
        if(i%56712)
            s+='A'+rand()%26;
        else
            s+=' ';


    fin<<s;

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
