#include <iostream>

using namespace std;

int i,j,n,m;
int nr,ok,v[30][30],mx,p,bkt[5],k;

void functie(int a,int b)
{
    for(i=1; i<=n; ++i)
        swap(v[i][a],v[i][b]);
    mx=0;
    for(i=1; i<=n; ++i)
    {
        nr=0;
        for(j=1; j<=m; ++j)
            if(v[i][j]!=j)
                ++nr;
        mx=max(mx,nr);
    }
    if(mx<3)
        ok=1;
    for(i=1; i<=n; ++i)
        swap(v[i][a],v[i][b]);
}

int main()
{
    cin>>n>>m;
    ok=1;
    for(i=1; i<=n; ++i)
    {
        nr=0;
        for(j=1; j<=m; ++j)
        {
            cin>>v[i][j];
            if(v[i][j]!=j)
                ++nr;
        }
        if(nr>2 && nr<5)
        {
            ok=0;
            p=i;
        }
        if(nr>4)
        {
            cout<<"NO";
            return 0;
        }
    }
    if(ok)
        cout<<"YES";
    else
    {
        for(i=1; i<=m; ++i)
            if(v[p][i]!=i)
                bkt[++k]=i;
        if(k==3)
        {
            ok=0;
            nr=0;
            functie(bkt[1],bkt[2]);
            nr=0;
            functie(bkt[2],bkt[3]);
            nr=0;
            functie(bkt[1],bkt[3]);
        }
        else
        {
            ok=0;
            nr=0;
            functie(bkt[1],bkt[2]);

            nr=0;
            functie(bkt[1],bkt[3]);


            nr=0;
            functie(bkt[1],bkt[4]);


            nr=0;
            functie(bkt[2],bkt[3]);


            nr=0;
            functie(bkt[2],bkt[4]);


            nr=0;
            functie(bkt[3],bkt[4]);
        }
        if(ok)
            cout<<"YES";
        else
            cout<<"NO";
    }
}
