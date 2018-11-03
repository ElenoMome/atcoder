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

 
int choice69(int n, int res)
{
	int ans = 0;
	while(n/res)
	{
		ans++;
		n = n/res;
	}
	return ans;
}


//ここから書き始める
int main(int argc, char const *argv[])
{
	int N;
	cin >> N;

	int memo[N+1];
	memo[0] = 0;
	memo[1] = 1;

	FOR(i,2,N+1)
	{
		//dump(i)
		int k_max6 = choice69(i,6);
		int k_max9 = choice69(i,9);

		int res = memo[i-1] + 1;

		FOR(j,1,k_max6+1)
		{
			int choice = pow(6,j);
			int kouho = memo[i-choice] + 1;
			if(res > kouho) res = kouho;

		}

		FOR(j,1, k_max9+1)
		{
			int choice = pow(9,j);
			int kouho = memo[i-choice] + 1;
			if(res > kouho) res = kouho;

		}
		//dump(res)

		memo[i] = res;

	}
	cout << memo[N] << endl;



}
