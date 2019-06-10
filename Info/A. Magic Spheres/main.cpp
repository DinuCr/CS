#include <iostream>

using namespace std;
int a,b,c,x,y,z,s,s1,s2,s3,d;
int main()
{
    cin>>a>>b>>c>>x>>y>>z;
    s1=a-x;
    if(s1%2==1)
        s1--;
    s2=b-y;
    if(s2%2==1)
        s2--;
    s3=c-z;
    if(s3%2==1)
        s3--;
    if(s1>0)
        s+=s1;
        else
        d+=s1;
    if(s2>0)
        s+=s2;
        else
        d+=s2;
    if(s3>0)
        s+=s3;
        else
        d+=s3;
    if(s>=-2*d)
        cout<<"Yes";
    else
        cout<<"No";
}
