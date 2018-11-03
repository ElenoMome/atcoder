#define rep(i, n) for(int i = 0; i < (int)(n); i++) //定番のn回繰り返しを省略
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <cmath>
#define dump(x) cerr<<#x<<"="<<x<<endl 

using namespace std;
 

//ここから書き始める
int main(int argc, char const *argv[])
{
	int N, X;
	stack<int> yakusu;
	stack<int> yakusu_b;

	cin >> N >> X;

	int x[N];

	rep(i,N)
	{
		cin >> x[i];
	}

	rep(i,N)
	{
		x[i] = abs(x[i] - X);
		//dump(x[i]);
	}

	sort(x, x+N);
	int minx;
	rep(i, N)
	{
		if(x[i] != 0) 
		{
			minx = x[i];
			break;
		}

	}
	//dump(minx);

	rep(i, sqrt(minx)+1)
	{
		if(i == 0) continue;
		if(minx%i == 0) 
		{
			yakusu.push(i);
			yakusu_b.push(minx/i);

		}

	}
	int loop = SZ(yakusu_b);
	rep(i, loop)
	{
		yakusu.push(yakusu_b.top());
		yakusu_b.pop();
	}

	int ans = 0;

	while(1)
	{
		int kouho = yakusu.top();
		int flag = 0;
		rep(i, N)
		{
			if(x[i] % kouho != 0)
			{
				break;
			}
			if (i == N - 1) 
			{
				flag = 1;
				ans = kouho;
			}


		}
		if(flag==1)
		{
			break;
		}

	}

	cout << ans << endl;


    return 0;
}
