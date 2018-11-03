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
	int N, K;
	cin >> N >> K;
	LL ans;

	if(K%2 == 1)
	{
		cout << LL(pow(N / K, 3)) << endl;
	}
	else
	{
		cout << LL(pow(N / K, 3) + pow((N % K < K / 2 ? N / K : N / K + 1), 3)) << endl;
	}


}
