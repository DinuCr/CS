#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

char s[110];
int last,first,i,j,ok;

int main()
{
    cin.getline(s,110);
    int n = strlen(s);
    int last = 0;
    int first = 0;
    for(i=0; i<n; ++i)
        if(s[i]!=' ')
        {
            first=i;
            for(j=i+1; j<n; ++j)
                if(s[j]==' ')
                    break;
            last=j-1;
            if(last-first>=2)
                if((last-first)%2==0)
                {
                    ok=1;
                    s[(last+first)/2]=0;
                }
            i=last;
        }
    if(!ok)
    {
        cout<<"nu exista";
        return 0;
    }
    for(i=0; i<n; ++i)
        if(s[i]!=NULL)
            cout<<s[i];
}
