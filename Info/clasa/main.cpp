#include <iostream>
using namespace std;
class fractie
{
public:
    int nr,nm;
    void afis()
    {
        cout<<nr<<'/'<<nm<<'\n';
    }
    fractie(int i,int j)
    {
        nr=i;
        nm=j;
    }
    ~fractie()
    {
    }
    void sim()
    {
        int mn=min(this->nr,this->nm);
        for(int i=mn;i>1;--i)
            if(this->nr%i==0 && this->nm%i==0)
            {
                this->nr/=i;
                this->nm/=i;
                break;
            }
    }
    fractie operator+(fractie a)
    {
        fractie f(2,3);
        f.nr=this->nr*a.nm+a.nr*this->nm;
        f.nm=a.nm*this->nm;
        f.sim();
        return f;
    }
};
int main()
{
    fractie a(1,2),b(2,3);
    a=a+b;
    a.afis();
}
