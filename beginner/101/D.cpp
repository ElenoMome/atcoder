#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>

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
typedef long double LD;

 
 LL kplus(LL num)
 {
 	LL dig,sum = 0;
 	while(num)
 	{
 		dig = num % 10;
 		sum += dig;
 		num = num / 10;
 	}

 	return sum;

 }

//ここから書き始める
int main(int argc, char const *argv[])
{
	LL K;
	cin >> K;

	if(K < 10)
	{
		REP(i,K)
		{
			cout << i << endl;
		}
	}
	else
	{
		FOR(i,1,10)
		{
			cout << i << endl;
		}
		LL i = 10;
		LL count = 9;
		while(1)
		{
			LL res = (i - 9) * 10 + 9;
			//dump(res)
			//dump(kplus(res))
			//dump(kplus(res + 10))
			if( (LD(res)) / kplus(res) < (LD(res+10)) / kplus(res + 10))
			{
				cout << res << endl;
				count++;
			}
			i++;

			if(count == K) break;
		}

	}


}
