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
const int MAX_N = 1e5+10;
int dp[MAX_N][3]; 

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    memset(dp,0,sizeof(dp));
    int N;
    cin >> N;
    int a[N],b[N],c[N];


    REP(i,N)
    {
        cin >> a[i] >> b[i] >> c[i];
    }
    dp[1][0] = a[0];
    dp[1][1] = b[0];
    dp[1][2] = c[0];

    for(int i=2; i <= N; i++)
    {
        dp[i][0] = max(dp[i-1][1], dp[i-1][2]) + a[i-1];
        dp[i][1] = max(dp[i-1][0], dp[i-1][2]) + b[i-1];
        dp[i][2] = max(dp[i-1][0], dp[i-1][1]) + c[i-1];
    }

    cout << max(max(dp[N][0], dp[N][1]), dp[N][2]) << endl;


}
