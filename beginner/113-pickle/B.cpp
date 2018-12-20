#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

#define DEBUG_ //!!提出時にコメントアウト!!
#ifdef DEBUG_
	#define dump(x)  cerr << #x << " = " << (x) << endl;
#else
	#define dump(x)  ; //何もしない文
#endif

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n)  FOR(i,0,n)
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換

typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef long long LL; 



//ここから書き始める
int main(int argc, char const *argv[])
{
	int N,T,A;
	cin >> N >> T >> A;

	int h[N];

	REP(i,N)
	{
		cin >> h[i];
	}
	float t;

	int ans = 0;
	t = T - h[0] * 0.006;
	float sa = abs(A - t);

	FOR(i,1,N)
	{
		float tmp_t = T - h[i] * 0.006;
		float tmp_sa = abs(A - tmp_t);
		if(tmp_sa < sa)
		{
			t = tmp_t;
			sa = tmp_sa;
			ans = i;
		}
	}
	cout << ans + 1 << endl;


}
