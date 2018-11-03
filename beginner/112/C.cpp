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
	LL N;
	cin >> N;
	LL x[N],y[N],h[N];
	tuple<long long, long long, long long> G = make_tuple(-1,-1,-1);
	REP(i, N)
	{
		cin >> x[i] >> y[i] >> h[i];
		if(h[i] >= 1) 
		{
			G = make_tuple(x[i], y[i], h[i]);
		}
	}
	//頂上探索
	REP(xkouho, 101)
	{
		REP(ykouho, 101)
		{
			LL hkouho = get<2>(G) + abs(xkouho - get<0>(G)) + abs(ykouho - get<1>(G));
			bool flag = true;
			REP(i,N)
			{
				LL height = max(0LL, hkouho - abs(xkouho - x[i]) - abs(ykouho - y[i]));
				if(height != h[i]) flag = false;
			}
			if(flag == true) cout << xkouho << " " << ykouho << " " << hkouho << endl;
		}
	}



}
