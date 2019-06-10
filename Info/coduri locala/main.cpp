#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
ifstream f("coduri.in");
ofstream g("coduri.out");
struct sir
{
    string s;
};
sir v[17];
int n,h,b,nr;
char c;
void hexa()
{
    for(int i=1; i<=h; i++)
    {
        f>>c;
        if(c<='F' && c>='A')
            c=c-'A'+10;
        else
            c=c-'0';
        g<<v[c].s;
    }
}
void bi()
{
    char c1,c2,c3,c4;
    for(int i=1; i<=b; i+=4)
    {
        f>>c1>>c2>>c3>>c4;
        int nr=c4-'0'+(c3-'0')*2+(c2-'0')*4+(c1-'0')*8;
        if(nr<10)
            g<<nr;
        else
        {
            switch(nr)
            {
            case 10:
                g<<'A';
                break;
            case 11:
                g<<'B';
                break;
            case 12:
                g<<'C';
                break;
            case 13:
                g<<'D';
                break;
            case 14:
                g<<'E';
                break;
            case 15:
                g<<'F';
                break;
            }
        }
    }
}
void trans()
{
    char H[10],B[35];
    for(int i=1;i<=h;i++)
    f>>H[i];
    for(int i=1;i<=b;i++)
    f>>B[i];
    int nr1,nr2;
    for(int i=1,j=1;i<=b;i+=4,j++)
    {
        nr1=0,nr2=0;
        if(H[j]=='X')
            nr1++;
        if(B[i]=='X')
            nr2++;
        if(B[i+1]=='X')
            nr2++;
        if(B[i+2]=='X')
            nr2++;
        if(B[i+3]=='X')
            nr2++;
        if(nr1==1 && nr2>0)
        {
            g<<'0';
            nr++;
            return;
        }
        else
        if(H[j]=='X' && nr1==1)
        {
            int x=B[i+3]-'0'+(B[i+2]-'0')*2+(B[i+1]-'0')*4+(B[i]-'0')*8;
            if(x<10)
                H[j]=x+'0';
            else
            switch(x)
            {
            case 10:
                H[j]='A';
                break;
            case 11:
                H[j]='B';
                break;
            case 12:
                H[j]='C';
                break;
            case 13:
                H[j]='D';
                break;
            case 14:
                H[j]='E';
                break;
            case 15:
                H[j]='F';
                break;
            }
        }
    }
    for(int i=1;i<=h;i++)
        g<<H[i];
}
int main()
{
    f>>n>>h>>b;
    v[0].s="0000";
    v[1].s="0001";
    v[2].s="0010";
    v[3].s="0011";
    v[4].s="0100";
    v[5].s="0101";
    v[6].s="0110";
    v[7].s="0111";
    v[8].s="1000";
    v[9].s="1001";
    v[10].s="1010";
    v[11].s="1011";
    v[12].s="1100";
    v[13].s="1101";
    v[14].s="1110";
    v[15].s="1111";
    for(int i=1; i<=n; i++)
    {
        f>>c;
        switch(c)
        {
        case 'H':
            hexa();
            break;
        case 'D':
            bi();
            break;
        case 'U':
            trans();
            break;
        }
        g<<'\n';
    }
    g<<nr;
}
