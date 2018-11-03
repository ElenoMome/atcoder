#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cassert>
#include <functional>

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
	int N,M;
	cin >> N >> M;

	LL x[N], y[N], z[N];
	LL sum[N];
	REP(i,N)
	{
		cin >> x[i] >> y[i] >> z[i];
	}

	LL kouho[8]; //ppp,ppn,pnp,pnn,npp,npn,nnp,nnn
	REP(i,8)
	{
		kouho[i] = 0;
	}

	//ppp
	REP(i,N)
	{
		sum[i] = x[i] + y[i] + z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[0] += sum[i];
	}

	//ppn
	REP(i,N)
	{
		sum[i] = x[i] + y[i] - z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[1] += sum[i];
	}


	//pnp
	REP(i,N)
	{
		sum[i] = x[i] - y[i] + z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[2] += sum[i];
	}

	//pnn
	REP(i,N)
	{
		sum[i] = x[i] - y[i] - z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[3] += sum[i];
	}


	//npp
	REP(i,N)
	{
		sum[i] = -x[i] + y[i] + z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[4] += sum[i];
	}

	//npn
	REP(i,N)
	{
		sum[i] = -x[i] + y[i] - z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[5] += sum[i];
	}

	
	//nnp
	REP(i,N)
	{
		sum[i] = - x[i] - y[i] + z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[6] += sum[i];
	}

	//nnn
	REP(i,N)
	{
		sum[i] = -x[i] - y[i] - z[i];
	}
	sort(sum, sum+N, greater<LL>());
	REP(i,M)
	{
		kouho[7] += sum[i];
	}


	sort(kouho, kouho+8, greater<LL>());

	cout << kouho[0] << endl;

}
