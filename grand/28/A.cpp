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

 
long long int gcd(long long int a, long long int b) {
	if (a < b)swap(a, b);
	while (b) {
			a %= b;
			swap(a, b);
		}
		return a;
	}


//ここから書き始める
int main(int argc, char const *argv[])
{
	int N, M;
	cin >> N >> M;
	string S, T;
	cin >> S >> T;

	auto nmgcd = gcd(N,M);
	int n = N / nmgcd;
	int m = M/ nmgcd;

	int loop = nmgcd;
	int flag = 0;


	FOR(i, 0, loop)
	{
		if(S[i * n] != T[i * m])
		{
			cout << -1 << endl;
			flag = 1;
			break;
		}

	}
	if(flag == 0)
	{
		LL before_ans = N;
		LL before_ans1 = m;
		LL ans = before_ans1 * before_ans;
		cout <<  ans << endl;
	}



}
