#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>

using namespace std;

//#define DEBUG_ //!!提出時にコメントアウト!!
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

int get_mojisu(int i)
{
	int ans = 1;
	while(i / 10)
	{
		ans++;
		i /= 10;
	}

	return ans;
}



//ここから書き始める
int main(int argc, char const *argv[])
{
	int N,M;
	cin >> N >> M;

	vector<tuple<int,int,int>> city(M);
	int p_inf[N];
	REP(i,N+1)
	{
		p_inf[i] = 1;
	}
	string ans[M];

	REP(i,M)
	{
		int tmp1,tmp0;
		//cin >> get<1>(city[i]) >> get<0>city[i];
		cin >> tmp1 >> tmp0;
		city[i] = make_tuple(tmp0,tmp1,i);
	}
	int kami,simo;

	sort(city.begin(), city.end());

	REP(i,M)
	{
		string kami_st,simo_st;
		int ken = get<1>(city[i]);
		kami_st = to_string(ken);
		dump(kami_st)
		simo = p_inf[ken];
		simo_st = to_string(simo);
		dump(simo_st)
		p_inf[ken]++;

		int ken_mojisu = get_mojisu(ken);
		dump(ken_mojisu)
		int num_mojisu = get_mojisu(simo);
		dump(num_mojisu)
		REP(t,6-ken_mojisu)
		{
			kami_st = '0' +  kami_st;
			dump(kami_st)
		}
		REP(t,6-num_mojisu)
		{
			simo_st = '0' + simo_st;
			dump(simo_st)
		}

		ans[get<2>(city[i])] = kami_st + simo_st;



	}
	REP(i,M)
	{
		cout << ans[i] << endl;
	}


	

}
