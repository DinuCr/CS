#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int v[1000];
int ans[1000];
int ok,n,m,i,j,last;
vector <pair<int,int> > raspund;

#define mp make_pair

void eat(int lims,int limd,int last)
{
    int p=-1;
    int st,dr,siz;
    for(int i=lims; i<=limd; ++i)
    {
        st=i-1;
        dr=i+1;
        siz=v[i];
        while(st>=lims || dr<=limd)
        {
            if(st>=lims && siz>v[st])
            {
                siz+=v[st];
                --st;
            }
            else
            if(dr<=limd && siz>v[dr])
            {
                siz+=v[dr];
                ++dr;
            }
            else
            break;
        }
        if(st==lims-1 && dr==limd+1)
        {
            p=i;
            break;
        }
    }
    if(p==-1)
    {
        ok=0;
        return;
    }
    else
    {
        st=p-1;
        dr=p+1;
        siz=v[p];
        int nr = last+p-lims+1;
        while(st>=lims || dr<=limd)
        {
            if(st>=lims && siz>v[st])
            {
                raspund.push_back(mp(nr,0));
                --nr;
                siz+=v[st];
                --st;
            }
            else
            if(dr<=limd && siz>v[dr])
            {
                raspund.push_back(mp(nr,1));
                siz+=v[dr];
                ++dr;
            }
        }
    }
}

int main()
{
    cin>>n;
    for(i=1; i<=n; ++i)
        cin>>v[i];
    cin>>m;
    for(i=1; i<=m; ++i)
        cin>>ans[i];
    last=1;
    for(i=1; i<=m; ++i)
    {
        int s = 0;
        for(j=last; s<ans[i] && j<=n; ++j)
            s+=v[j];
        if(s!=ans[i])
        {
            cout<<"NO";
            return 0;
        }
        ok=1;
        eat(last,j-1,i-1);
        last=j;
        if(ok==0)
        {
            cout<<"NO";
            return 0;
        }
    }
    if(last<=n)
    {
        cout<<"NO";
        return 0;
    }
    cout<<"YES"<<'\n';
    for(i=0; i<raspund.size(); ++i)
    {
        cout<<raspund[i].first<<' ';
        switch(raspund[i].second)
        {
        case 0:
            cout<<"L\n";
            break;
        case 1:
            cout<<"R\n";
        }
    }
}
