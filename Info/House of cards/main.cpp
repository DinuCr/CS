#include <fstream>

using namespace std;

ifstream f("input.txt");
ofstream g("output.txt");

long long N, R, C, dif, rez;

int main()
{

    int N;

    if(N>=100000)
    {
        unsigned int R,C,dif,rez;
        f >> N >> R >> C;
        if(C==1)
        {
            g<<R;
            return 0;
        }
        rez = 1LL*R*(1LL*R+1LL)/2LL - ((1LL*R-1LL*C)*(1LL*R-1LL*C+1LL)/2LL + 1LL*C*(1LL*C-1LL)/2LL);
        g << rez;
    }
    else
    {
        int R,C,dif,rez;
        f >> N >> R >> C;
        if(C==1)
        {
            g<<R;
            return 0;
        }
        rez = 1LL*R*(1LL*R+1LL)/2LL - ((1LL*R-1LL*C)*(1LL*R-1LL*C+1LL)/2LL + 1LL*C*(1LL*C-1LL)/2LL);
        g << rez;
    }
    return 0;
}
