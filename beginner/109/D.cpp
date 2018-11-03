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
	queue<PII> que;
	int count = 0;

	REP(i, H)
	{
		REP(j, W)
		{
			cin >> a[i][j];
		}
	}


	//本処理
	REP(i, W*H)	
	{
		int retu_mae = i % W;
		int gyo_mae = i / W;

		if(gyo_mae % 2 == 1) //奇数行のとき
		{
			retu_mae = W - 1 - retu_mae;
			int retu_ato = (retu_mae == 0? 0 : retu_mae - 1);
			int gyo_ato = (retu_mae == 0? gyo_mae + 1 : gyo_mae);
			//dump(gyo_mae)
			//dump(retu_mae)
			//dump(a[gyo_mae][retu_mae])
			//dump(gyo_ato)
			//dump(retu_ato)

			if(a[gyo_mae][retu_mae] % 2 == 1)
			{
				if(i != H * W - 1)
				{
					count++;
					a[gyo_ato][retu_ato]++;
					//cout << gyo_mae + 1 << " " << retu_mae + 1 << " " << gyo_ato + 1 << " " << retu_ato + 1 << endl;

					PII pos1, pos2;
					pos1.first = gyo_mae + 1;
					pos1.second = retu_mae + 1;
					pos2.first = gyo_ato + 1;
					pos2.second = retu_ato + 1;

					que.push(pos1);
					que.push(pos2);

				}
			}


		}
		else //偶数行のとき
		{
			int retu_ato = (retu_mae == W-1? W-1 : retu_mae + 1);
			int gyo_ato = (retu_mae == W-1? gyo_mae + 1 : gyo_mae);

			//dump(gyo_mae)
			//dump(retu_mae)
			//dump(a[gyo_mae][retu_mae])
			//dump(gyo_ato)
			//dump(retu_ato)

			if(a[gyo_mae][retu_mae] % 2 == 1)
			{
				if(i != H * W - 1)
				{
					count++;
					a[gyo_ato][retu_ato]++;
					//cout << gyo_mae + 1 << " " << retu_mae + 1 << " " << gyo_ato + 1 << " " << retu_ato + 1 << endl;

					PII pos1, pos2;
					pos1.first = gyo_mae + 1;
					pos1.second = retu_mae + 1;
					pos2.first = gyo_ato + 1;
					pos2.second = retu_ato + 1;

					que.push(pos1);
					que.push(pos2);

				}
			}

		}




	}

	cout << count << endl;
	REP(i, count)
	{
		cout << que.front().first << " " << que.front().second << " ";
		que.pop();

		cout << que.front().first << " " << que.front().second << endl;
		que.pop();
	}


}
