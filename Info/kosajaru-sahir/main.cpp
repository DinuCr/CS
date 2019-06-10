#include <iostream>
#include<fstream>
using namespace std;
int a[100][100],at[100][100],viz[100],postord[100],n,k,i,j;
void citeste()
{
    ifstream f("graf.in");
    f>>n;
    while(f>>i>>j)
    {
        a[i][j]=1;
        at[j][i]=1;
    }
    f.close();
}

void df(int x)
{
    int l;
    viz[x]=1;
    for(l=1;l<=n;l++)
    if(a[x][l]==1 && viz[l]==0)
    df(l);
    postord[++k]=x;
}

void dft(int x)
{
    int l;
    viz[x]=0;
    cout<<x<<' ';
    for(l=1;l<=n;l++)
    if(at[x][l]==1 && viz[l]==1)
    dft(l);
}

void tareconexe()
{
    int i,nc=0;
    for(i=1;i<=n;i++)
    if(!viz[i])
    df(i);
    for(i=n;i>0;i--)
    if(viz[postord[i]])
    {
        nc++;
        cout<<"componenta tare conexa "<<nc<<endl;
        dft(postord[i]);
    }
}
int main()
{
    citeste();
    tareconexe();
}
