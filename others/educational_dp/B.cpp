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
const int INF = 1e9+7;
const int MAX_N = 1e5+10;
int dp[MAX_N];

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N,K;
    cin >> N >> K;
    VI h(N);
    REP(i,N)
    {
        cin >> h[i];
    }

    memset(dp, 0, sizeof(dp));

    for(int i=N-1; i>0; i--)
    {
        int tmp=INF;
        FOR(j,1,K+1)
        {
            dump(i)
            dump(j)
            if(i+j > N) break;
            int kouho = dp[i+j] + abs(h[i-1] - h[i-1+j]);
            dump(kouho)
            if(kouho < tmp) tmp = kouho;
        }
        dp[i] = tmp;
        dump(i)
        dump(dp[i])
    }

    cout << dp[1] << endl;



}
