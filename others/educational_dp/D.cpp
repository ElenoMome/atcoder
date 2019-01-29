#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cmath>
#include <tuple>
#include <cstdio>
#include <bitset>
#include <sstream>
#include <iterator>
#include <numeric>
#include <map>
#include <cstring>

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

template <typename T>
std::string printVector(const std::vector<T> &data)
{
    std::stringstream ss;
    std::ostream_iterator<T> out_it(ss, ", ");
    ss << "[";
    std::copy(data.begin(), data.end() - 1, out_it);
    ss << data.back() << "]";
    return ss.str();
}

const int MOD = 1e9+7;
const int MAX_N = 105;
const int MAX_W = 1e5+10;
LL dp[MAX_N][MAX_W];
int v[MAX_N];
int w[MAX_N];

int N,W;

// i番目以降で重量j以下の制約での最大価値
LL rec(int i, int j)
{
    LL res;
    if(dp[i][j] != -1) return dp[i][j];

    if(i == N) res = 0;
    else if(j < w[i]) res = rec(i+1, j);
    else res = max(rec(i+1,j), rec(i+1, j- w[i]) + v[i]);

    dp[i][j] = res;
    dump(i)
    dump(j)
    dump(res)

    return res;
}


//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    cin >> N >> W;
    REP(i,N)
    {
        cin >> w[i] >> v[i];
    }

    memset(dp,-1,sizeof(dp));

    cout << rec(0,W) << endl;

}
