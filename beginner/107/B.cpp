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
	int H,W;
	cin >> H >> W;
	int a[H][W];

	string m[H];
	REP(i, H)
	{
		cin >> m[i];
	}

	int row_mark[H][W];
	int column_mark[H][W];
	int mark[H][W];
	REP(i, H)
	{
		REP(j, W)
		{
			if(m[i][j] == '#') a[i][j] = 1;
			if(m[i][j] == '.') a[i][j] = 0;
			row_mark[i][j] = 0;
			column_mark[i][j] = 0;
		}
	}


	REP(i, H)
	{
		REP(j, W)
		{
			if(a[i][j] == 1)
			{
				REP(k, H) row_mark[k][j] = 1;
				REP(l, W) column_mark[i][l] = 1;
			}

		}
	}
	REP(i, H)
	{
		REP(j,W)
		{
			mark[i][j] = row_mark[i][j] * column_mark[i][j];
		}
	}

	REP(i, H)
	{
		int sum = 0;
		REP(k,W)
		{
			sum += mark[i][k];
		}
		if(sum == 0) continue;


		REP(j, W)
		{
			if(mark[i][j] == 1) cout << (a[i][j] == 1 ? "#" : ".");
		}
		cout << endl;
	}


}
