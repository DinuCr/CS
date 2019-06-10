#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

ifstream fin("triang.in");

#define nmax 510
#define mp make_pair
#define f first
#define s second


vector <pair<double,double> > v;
double d[nmax][nmax];
int ans[nmax][nmax];
int i,j,n,k;

inline double dist(pair<double,double> a,pair<double,double> b)
{
    return sqrt((a.f-b.f)*(a.f-b.f)+(a.s-b.s)*(a.s-b.s));
}

double P(pair<double,double> a,pair<double,double> b,pair<double,double> c)
{
    return dist(a,b)+dist(b,c)+dist(a,c);
}

void rasp(int i,int j,int k)
{
    if(k==0)
        return;
    cout<<i<<' '<<j<<' '<<k<<'\n';
    rasp(i,k,ans[i][k]);
    rasp(k,j,ans[k][j]);
}

int main()
{
    fin>>n;
    v.push_back(mp(0,0));
    for(i=1; i<=n; ++i)
    {
        double a,b;
        fin>>a>>b;
        v.push_back(mp(a,b));
    }
    for(int dif=2; dif<n; ++dif)
        for(i=1; i<=n; ++i)
        {
            j=i+dif;
            for(k=i+1; k<j; ++k)
                if(d[i][j]==0 || d[i][j]>d[i][k]+d[k][j]+P(v[i],v[j],v[k]))
                {
                    ans[i][j]=k;
                    d[i][j]=d[i][k]+d[k][j]+P(v[i],v[j],v[k]);
                }
        }
    cout<<d[1][n]<<'\n';
    rasp(1,n,ans[1][n]);

    double sum=0;
    cin>>n;
    for(i=1; i<=n; ++i)
    {
        int a,b,c;
        cin>>a>>b>>c;
        sum+=P(v[a],v[b],v[c]);
    }
    cout<<sum;
}
