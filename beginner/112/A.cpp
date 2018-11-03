#define rep(i, n) for(int i = 0; i < (int)(n); i++) //定番のn回繰り返しを省略
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 

//ここから書き始める
int main(int argc, char const *argv[])
{
    int a,b,n;
    cin >> n;

    if(n == 1)
    {
        cout << "Hello World" << endl;
    }
    if(n == 2)
    {
        cin >> a;
        cin >> b;
        cout << a+b << endl;
    }

    return 0;
}

6 4
-30 -10 0 10 20 50