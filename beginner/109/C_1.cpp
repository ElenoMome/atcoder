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
	int N,X;

	cin >> N >> X;

	int x[N];

	REP(i, N)
	{
		cin >> x[i];
	}

	REP(i, N)	
	{
		x[i] = abs(x[i] - X);
	}

	int ans;
	ans = x[0];

	REP(i, N)
	{
		if(i==0) continue;
		ans = gcd(ans, x[i]);
	}

	cout << ans << endl;


}
