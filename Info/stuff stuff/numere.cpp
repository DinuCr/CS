#include<iostream>
#include<fstream>
#include<string>
#include<strstream>
using namespace std;
ifstream f("numere.in");
int v[100][100],n,i,j,w[4],x,a1,b1,c1,c[4];
char linie[255];
int main()
{
    while(!f.eof())
    {
        f.getline(linie,255);
        istrstream sir(linie,255);
        n=1;
        while(sir>>w[n])
        {
           n++;
        }
        n--;
        if(n!=0)
        {
            if(n==3)
            {
                c[1]=0;
                c[2]=0;
                c[3]=0;
                x=0;
                while(w[1]>=x)
                {
                    c[1]++;
                    x+=c[1];
                }
                c[1]--;
                x=0;
                while(w[2]>=x)
                {
                    c[2]++;
                    x+=c[2];
                }
                c[2]--;
                x=0;
                while(w[3]>=x)
                {
                    c[3]++;
                    x+=c[3];
                }
                c[3]--;
                if((c[1]!=c[2] && c[2]!=c[3] && c[3]!=c[1]) || (c[1]==c[2] && c[2]==c[3]))
                cout<<"NU";
                else
                {
                    a1=1;
                    b1=1;
                    c1=1;
                    for(i=1;i<=2;i++)
                    for(j=i+1;j<=3;j++)
                    if(w[i]<w[j])
                    {
                        swap(w[j],w[i]);
                        swap(c[i],c[j]);
                    }
                    while(w[1]!=v[c[1]][a1])
                    a1++;
                    while(w[2]!=v[c[2]][b1])
                    b1++;
                    while(w[3]!=v[c[3]][c1])
                    c1++;
                    if((c[1]==c[2] && b1==c1)|| (a1==b1 && c[2]==c[3]))
                    cout<<"TRIUNGHI";
                    else
                    cout<<"NU";
                }
            }
            else
            cout<<"NU";
        }
    }
    f.close();
    return 0;
}
