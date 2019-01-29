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

const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

const int MOD = 1e9+7;
const int MAX_N = 105;
const int MAX_V = 1e5+10;

LL dp[MAX_N][MAX_V];

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	

    int N,W;
    cin >> N >> W;
    VI w(N),v(N);
    REP(i,N)
    {
        cin >> w[i] >> v[i];
    }


    REP(i,MAX_N)
    {
        REP(j,MAX_V)
        {
            dp[i][j] = LINF;
        }
    }

    dp[0][0] = 0;


    REP(i,N)
    {
        for(int tv = 0; tv <= MAX_V; ++tv)
        {
            if(tv >= v[i])
            {
                dp[i+1][tv] = min({dp[i][tv], dp[i][tv-v[i]] + w[i]});
            }
            else
            {
                dp[i+1][tv] = dp[i][tv];
            }
        }
    }
    LL ans = 0;

    REP(n,N+1)
    {
        REP(i,100)
        {
        if(dp[n][i] != LINF)
        {
            dump(n)
            dump(i)
            dump(dp[n][i])
        }
        }
    }

    for(int i = MAX_V-1; i >= 0; --i)
    {
        if(dp[N][i] != LINF)
        {
            dump(i)
            dump(dp[N][i])
        }
        if(dp[N][i] <= W)
        {
            dump(W)
            dump(dp[N][i] <= W)
            ans = i;
            break;
        }
    }

    cout << ans << endl;


}
