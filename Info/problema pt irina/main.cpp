#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
char s[2000];
ifstream f("problema.in");
int n,i;
int main()
{
    f.get(s,1000);
    n=strlen(s);
    //mai rapid decat sa parcurga de fiecare data sa imi spuna cat are, si mai usor de scris
    for(i=0;i<n;i++)
    {
        cout<<s[i];
        if(i%30==29)
            if(i/30%2==1)
            cout<<'\n';
    }
    //asa deci, eu scriu fiecare element si pt ca e de la 0, la dupa primele 30 o sa fiu la 29 deci de aia e restul ala si dupa e la fel ca mna mai parcurg 30. si trebuie sa am endl la fiecare 30 dar la fiecare 60 este deja si de aia mai fac catul acolo sa vad daca sunt la perioada de 30 sau de 60

}
