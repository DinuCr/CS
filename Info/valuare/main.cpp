#include<iostream>
#include<fstream>
using namespace std;
ifstream f("valuare.in");
ofstream g("valuare.out");
long long x,b,p,i,s,a,b2,A,B;
int mul_inv(int a, int b)
{
	int b0 = b, t, q;
	int x0 = 0, x1 = 1;
	if (b == 1) return 1;
	while (a > 1) {
		q = a / b;
		t = b, b = a % b, a = t;
		t = x0, x0 = x1 - q * x0, x1 = t;
	}
	if (x1 < 0) x1 += b0;
	return x1;
}
int main()
{
    f>>b>>p;
    x=b;a=b;
    while(x)
    {
        if(x%2==1)
        {
            x--;
            b2=a%p;
        }
        while(x%2==0)
        {
            x/=2;
            a=(a%p)*(a%p);
        }
    }
    b2=(b2*a)%p;
    A=b2-1;
    A%=p;
    B*=(b-1);
    t= cmmdc ( B, p)
    s= B/t
    v=mul_inv(s,p);

}
