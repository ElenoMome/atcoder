#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#define dump(x)  cerr << #x << " = " << (x) << endl;

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL; 

 

//ここから書き始める
int main(int argc, char const *argv[])
{
	int N,K;
	cin >> N >> K;

	int x[N];
	int mcount = 0, pcount = 0, zero = 0;
	// 0があると面倒なので，別途処理
	REP(i, N)
	{
		int tmp;
		cin >> tmp;

		if(tmp == 0)
		{
			zero++;
			continue;
		}
		if(tmp < 0) 
		{
			x[i - zero] = -tmp; 
			mcount++;
		}
		if(tmp > 0) 
		{
			x[i - zero] = tmp; 
			pcount++;
		}
	}
	if(zero == 1) K--;


	if(K == 0)
	{
		cout << 0 << endl;
	}
	else
	{
		LL ans = 3000000000;
		REP(i, K+1) // iは左に行く数
		{
			int left = i;
			//dump(left);
			int right = K - i;
			//dump(right);
			if(left > mcount || right > pcount) continue;

			int ldis;
			if (left == 0) 
			{
				ldis = 0;
			}
			else
			{
				ldis = x[mcount - i];
			}
			//dump(ldis)

			int rdis;

			if (right == 0)
			{
				rdis = 0;
			}
			else
			{
				rdis = x[mcount + right - 1];
			}
			//dump(rdis)

			int kouho1 = ldis * 2 + rdis;
			int kouho2 = rdis * 2 + ldis;
			//dump(kouho1)
			//dump(kouho2)

			int kouho = (kouho1 > kouho2? kouho2 : kouho1);

			if(ans > kouho) ans = kouho;

		}

		cout << ans << endl;
	}



}
