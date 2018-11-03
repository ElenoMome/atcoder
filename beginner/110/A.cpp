#define rep(i, n) for(int i = 0; i < (int)(n); i++) //定番のn回繰り返しを省略
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 

//ここから書き始める
int main(int argc, char const *argv[])
{
	int x[3];
	cin >> x[0] >> x[1] >> x[2];

	sort(x, x+3);

	cout << x[2] * 10 + x[1] + x[0] << endl;


    return 0;
}
