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

vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}    

const int MAX_N = 101;

const int MOD = 1e9+7;
double dp[MAX_N][65][65][65];

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    LL N,D;
    cin >> N >> D;

    memset(dp,0,sizeof(dp));
    dp[0][0][0][0] = 1;

    auto pfac = prime_factorize(D);
    bool ok = 1;
    int J=0,K=0,L=0;
    for(auto e : pfac)
    {
        dump(e.first)
        dump(e.second)
        if(e.first == 2) J = e.second;
        else if(e.first == 3) K = e.second;
        else if(e.first == 5) L = e.second;
        else ok = 0;
    }
    if(!ok)
    {
        cout << 0 << endl;
        return 0;
    } 


    REP(i,N)
    {
        REP(j,J+1)
        //REP(j,3)
        {
            REP(k,K+1)
            //REP(k,3)
            {
                REP(l,L+1)
                //REP(l,3)
                {
                    dp[i+1][j][k][l] += (1.0/6.0) * dp[i][j][k][l];

                    dp[i+1][min(j+1, J)][k][l] += (1.0/6.0) * dp[i][j][k][l];
                    dp[i+1][j][min(k+1,K)][l] += (1.0/6.0) * dp[i][j][k][l];
                    dp[i+1][min(j+2,J)][k][l] += (1.0/6.0) * dp[i][j][k][l];
                    dp[i+1][j][k][min(l+1,L)] += (1.0/6.0) * dp[i][j][k][l];
                    dp[i+1][min(j+1,J)][min(k+1,K)][l] += (1.0/6.0) * dp[i][j][k][l];
                }
            }
        }
    }




    cout << dp[N][J][K][L] << endl;


}
