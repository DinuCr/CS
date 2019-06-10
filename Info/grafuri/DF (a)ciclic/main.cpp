#include<iostream>
#include<fstream>
using namespace std;
fstream f("df.in");
int ok,v[100][100],viz[100],n,i,a,b,buffer[1000];
class InputReader {
    public:
        InputReader() {}
        InputReader(const char *file_name) {
            input_file = fopen(file_name, "r");
            cursor = 0;
            fread(buffer, SIZE, 1, input_file);
        }
        inline InputReader &operator >>(int &n) {
            while(buffer[cursor] < '0' || buffer[cursor] > '9') {
                advance();
            }
            n = 0;
            while('0' <= buffer[cursor] && buffer[cursor] <= '9') {
                n = n * 10 + buffer[cursor] - '0';
                advance();
            }
            return *this;
        }
    private:
        FILE *input_file;
        static const int SIZE = 1 << 17;
        int cursor;
        char buffer[SIZE];
        inline void advance() {
            ++ cursor;
            if(cursor == SIZE) {
                cursor = 0;
                fread(buffer, SIZE, 1, input_file);
            }
        }
};
InputReader f1("F://df.in");
void df(int x,int t)
{
    viz[x]=1;
    cout<<x<<' ';
    int i;
    for(i=1;i<=v[x][0];i++)
    if(v[x][i]!=t)
    {
        if(viz[v[x][i]])
            ok=false;
        else
        df(v[x][i],x);
    }
}
int main()
{
    //f1.InputReader("df.in");
    for(i=1;i<=buffer[0]*2;i++)
    cout<<buffer[i]<<' ';
    for(i=1;i<=n;i++)
    {
        v[a][0]++;
        v[a][v[a][0]]=b;
        v[b][0]++;
        v[b][v[b][0]]=a;
    }
    ok=true;
    df(1,0);
    if(ok)
        cout<<"aciclic";
    else
        cout<<"ciclic";
}
