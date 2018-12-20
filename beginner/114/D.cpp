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


const int MOD = 1e9+7;

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N;
    cin >> N;
    map<int, int> prime_division;
    LL dp[101][101];
    REP(i,101)
    {
        REP(j,101)
        {
            dp[i][j] = 0;
        }
    }

    vector<int> div75 = {1,3,5,15,25,75};

    FOR(i,2,N+1)
    {
        auto res = prime_factorize(i);
        for(auto e : res)
        {
            prime_division[e.first] += e.second;
        }

    }

    VI nums;
    for(auto e : prime_division) nums.push_back(e.second);
    int len = nums.size();

    dp[0][1] = 1;

    for(int i=0; i < len; i++)
    {
        for(auto d1 : div75)
        {
            dump(d1)
            for(auto d2 : div75)
            {
                dump(d2)
                if(d1 * d2 <= 75 && nums[i]+1 >= d2)
                {
                    dp[i+1][d1*d2] += dp[i][d1];

                    dump(dp[i][d1])
                    dump(dp[i+1][d1*d2])
                }
            }
        }

    }
    cout << dp[len][75] << endl;

}
