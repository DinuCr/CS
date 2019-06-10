#include<iostream>
#include<fstream>
using namespace std;
ifstream f("kruskal.in");
int v[100][4],l[100],i,j,k,n,p,s,m1,m2;
int main()
{
    f>>n>>p;
    for(i=1;i<=n;i++)
    {
        f>>v[i][1]>>v[i][2]>>v[i][3];
    }
    for(i=1;i<=p;i++)
    l[i]=i;
    k=0;i=1;
    while(k<p-1)
    {
        if(l[v[i][1]]=!l[v[i][2]])
        {
            m1=min(l[v[i][1]],l[v[i][2]]);
            m2=max(l[v[i][1]],l[v[i][2]]);
            for(j=1;j<=p;j++)
            if(l[j]==m2)
            l[j]=m1;
            s+=v[i][3];
            k++;
            cout<<v[i][1]<<' '<<v[i][2]<<endl;
        }
        i++;
    }
    cout<<endl<<s;
    f.close();
}
