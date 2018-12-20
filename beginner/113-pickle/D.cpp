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
const int MOD=1e9+7;

int nth_bit(LL num, int n){
    return (num >> n) & 1;
}

inline int add(int x,int y)
{
    return (x + y)%MOD;
}
 
inline int sub(int x,int y)
{
    return (x+MOD-y)%MOD;
}
 
inline int mul(int x,int y)
{
    return (LL)x*y%MOD;
}

//ここから書き始める
int main(int argc, char const *argv[])
{
	int H,W,K;
	cin >> H >> W >> K;

	int dp[H][W];
	int num[W][W];
	REP(i,W)
	{
		REP(j,W) num[i][j] = 0;
	}



    REP(i,pow(2,W-1))
    {
    	bool ok = 1;
    	//重複チェック
    	REP(j,W-1)
    	{
    		if(nth_bit(i,j) == 1 && nth_bit(i,j+1) == 1) ok = 0;
    	}
    	if(!ok) continue;

    	int p[W];
    	REP(j,W) p[j] = j;
    	REP(j,W-1)
    	{
    		if(nth_bit(i,j) == 1) swap(p[j], p[j+1]);
    	}

    	REP(j,W) num[p[j]][j]++;

    }

    dp[0][0] = 1;
    FOR(i,1,W) dp[0][i] = 0;


    FOR(i,1,H+1)
    {
    	REP(j,W)
    	{
    		dp[i][j] = 0;
    		REP(k,W)
    		{
    			dp[i][j] = add(dp[i][j],mul(dp[i-1][k], num[k][j]));
    		}
    	}
    }



    cout << dp[H][K-1] << endl;



}
