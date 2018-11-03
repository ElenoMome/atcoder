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

 

//ここから書き始める
int main(int argc, char const *argv[])
{
	LL N,K;
	cin >> N >> K;
	LL a[N];
	REP(i,N) cin >> a[i];

	LL ans;
	//ans = (N - K) / (K - 1) + 1
	ans = ((N-K) + (K - 2)) / (K-1) + 1;
	cout << ans << endl;




}
