#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define s second
#define pb push_back

ofstream fout("9-caracatita.in");

int main()
{
	cin.sync_with_stdio(false);
	cout.sync_with_stdio(false);

    srand(time(NULL));

	int n = 500;
	int m = 100000;

	fout<<n<<'\n';

    string s;

    int last = 0;

	for(int i=1; i<=n; ++i)
    {
        int len = rand()%100 + 1;
        for(int j=1; j<=len; ++j)
        {
            int x = j;
            char c = 'a'+rand()%26;
            while(c != last)
            {
                c = 'a'+rand()%26;
                last = c;
            }
            while(x--)
            {
                fout<<c;
                s.pb(c);
            }
        }
        fout<<'\n';
    }

    fout<<m<<'\n';

    for(int i=1; i<=m; ++i)
    {
        int len = rand()%1000 + 1;

        int pos = 1LL * rand() * rand() * rand() * rand() % (s.length() - len);

        string curr = s.substr(pos, len);

        int x = 0;

        if(len/2>0)
            x = rand()%(len/2)+len/2;

        while(x--)
        {
            pos = rand()%curr.length();
            curr.erase(pos,1);
        }

        fout<<curr<<'\n';
    }
}
