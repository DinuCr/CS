#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
ifstream fin("virgule.out");
int main()
{
    char a[200];
    char b[200];
    fin>>a>>b;
    int n=strlen(a);
    int m=strlen(b);
    cout<<n<<' '<<m;
    for(int i=0; i<=n; ++i)
        if(a[i]!=b[i])
            cout<<"diferit";
}
