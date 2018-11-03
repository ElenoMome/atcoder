#define rep(i, n) for(int i = 0; i < (int)(n); i++) //定番のn回繰り返しを省略
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <math.h>
 
using namespace std;
 

//ここから書き始める
int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;

	stack<int> kouho;
	stack<int> kouho1;
	//mの約数をすべて求める
	rep(i, int(sqrt(m))+1)
	{
		if(i==0) continue;

		if(m%i == 0)
		{
			kouho.push(i);
			kouho1.push(i);
			//cout << i << ",";
		}

	}
	int loop1 = SZ(kouho1);
	int y;
	rep(i,loop1)
	{
		y = kouho1.top();
		kouho1.pop();
		kouho.push(m/y);

	}


	int x;
	int loop = SZ(kouho);
	//rep(i, loop)
	//{
	//	cout << kouho.top() << ",";
	//	kouho.pop();
	//}


	//候補を順にチェック
	rep(i, loop)
	{
		x = kouho.top();
		kouho.pop();
		if(n <= m/x)
		{
			cout << x << endl;
			break;
		}

	}

    return 0;
}
