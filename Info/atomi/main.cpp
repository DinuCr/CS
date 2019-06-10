#include <iostream>
#include <stack>
#include <cstring>

using namespace std;

#define mp make_pair
#define f first
#define s second

stack <pair<int,int> > q;
int i,nr;

int main()
{
    char sir[300];
    cin>>sir;
    int n = strlen(sir);
    q.push(mp(0,0));
    while(i<n)
    {
        if(sir[i]=='(')
        {
            q.push(mp(0,0));
            ++i;
        }
        else
        if(sir[i]=='A')
        {
            ++i;
            nr=0;
            while(sir[i]<='9' && sir[i]>='0')
            {
                nr=nr*10+sir[i]-'0';
                ++i;
            }
            if(nr==0)
                nr=1;
            q.top().f+=nr;
        }
        else
        if(sir[i]=='B')
        {
            ++i;
            nr=0;
            while(sir[i]<='9' && sir[i]>='0')
            {
                nr=nr*10+sir[i]-'0';
                ++i;
            }
            if(nr==0)
                nr=1;
            q.top().s+=nr;
        }
        else
        if(sir[i]==')')
        {
            int a = q.top().f;
            int b = q.top().s;
            q.pop();
            nr=0;
            ++i;
            while(sir[i]<='9' && sir[i]>='0')
            {
                nr=nr*10+sir[i]-'0';
                ++i;
            }
            if(nr==0)
                nr=1;
            q.top().f+=a*nr;
            q.top().s+=b*nr;
        }
    }
    cout<<q.top().f<<' '<<q.top().s;
}
