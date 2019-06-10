#include<fstream>
using namespace std;int s,n,i,j,x;ifstream f("clasic.in");ofstream g("clasic.out");int main(){f>>n;for(;i<2;i++){f>>n,s=0;for(j=0;j<n;j++)f>>x,s^=x;g<<s<<'\n';}}
