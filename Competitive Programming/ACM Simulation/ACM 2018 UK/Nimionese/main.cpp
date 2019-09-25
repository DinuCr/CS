#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define mp make_pair
#define f first
#define pb push_back

int i;
char s [50010];


int main()
{
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);

    cin.getline(s, sizeof(s));

    char last = 'a';

    string con = "bcdgknpt";
    string con2 = "BCDGKNPT";

    int ok = 0;

    int start = 1;

    for(i=0; s[i]; ++i)
    {
        if(s[i]==' ')
        {
            ok = 0;
            start = 1;
            continue;
        }
        if(s[i]=='-')
        {
            ok = 1;
            continue;
        }
        if(((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A')) && ok)
        {
            for(int j=0; j<con.length(); ++j)
                if(s[i]==con[j])
                    s[i]=last;
        }
        if(((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A')) && start)
        {
            int mn = 100;
            int pos = 0;
            start = 0;
            if((s[i]<='z' && s[i]>='a'))
            {
                for(int j=0; j<con.length(); ++j)
                    if(mn>abs(con[j]-s[i]))
                        mn =abs(con[j]-s[i]),pos = j;
                s[i]=con[pos];
            }
            else
            {
                for(int j=0; j<con2.length(); ++j)
                    if(mn>abs(con2[j]-s[i]))
                        mn =abs(con2[j]-s[i]),pos = j;
                s[i]=con2[pos];

            }
            last = con[pos];
        }
    }

    for(i=0; s[i]; ++i)
    {
        if((s[i]<='z' && s[i]>='a') || (s[i]<='Z' && s[i]>='A'))
            cout<<s[i];
        if(s[i]=='-')
            continue;
        if(s[i]==' ')
        {
            int ok1 = 0;
            for(int j=0; j<con.length(); ++j)
                if(s[i-1]==con[j] || s[i-1]==con2[j])
                    ok1=1;
            if(ok1==0)
            {
                cout<<' ';
                continue;
            }
            if(s[i-1]<='Z' && s[i-1]>='A')
                s[i-1]=s[i-1]-'A'+'a';
            int mn1 = abs(s[i-1]-'a');
            int mn2 = abs(s[i-1]-'o');
            int mn3 = abs(s[i-1]-'u');
            if(mn1 <= mn2 && mn1 <= mn3)
                cout<<"ah ";
            else if(mn2 <= mn1 && mn2 <= mn3)
                cout<<"oh ";
            else
                cout<<"uh ";
        }
    }
    int ok1 = 0;
            for(int j=0; j<con.length(); ++j)
                if(s[i-1]==con[j] || s[i-1]==con2[j])
                    ok1=1;
            if(ok1==0)
            {
                cout<<' ';
                return 0;
            }
            if(s[i-1]<='Z' && s[i-1]>='A')
                s[i-1]=s[i-1]-'A'+'a';
            int mn1 = abs(s[i-1]-'a');
            int mn2 = abs(s[i-1]-'o');
            int mn3 = abs(s[i-1]-'u');
            if(mn1 <= mn2 && mn1 <= mn3)
                cout<<"ah ";
            else if(mn2 <= mn1 && mn2 <= mn3)
                cout<<"oh ";
            else
                cout<<"uh ";


}
