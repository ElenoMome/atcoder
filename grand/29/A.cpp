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

template<typename T>
struct BIT {
    std::vector<T> dat;
 
    BIT(int n) : dat(n + 1) {}
 
    void add(int k, T v) {
        k++;
        while (k < dat.size()) {
            dat[k] += v;
            k += k & -k;
        }
    }
 
    T sum(int k) {
        k++;
        T ret = 0;
        while (k > 0) {
            ret += dat[k];
            k &= k - 1;
        }
        return ret;
    }
};

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    string S;
    cin >> S;
    VI conv(SZ(S));
    REP(i,SZ(S))
    {
        if(S[i] == 'B')
        {
            conv[i] = 1;
        }
        if(S[i] == 'W')
        {
            conv[i] = 0;
        }
    }

    BIT<int> bit(2 * 1e5 + 10);
    LL res = 0;
    REP(i,SZ(S))
    {
        res += i - bit.sum(conv[i]);
        bit.add(conv[i],1);
    }

    cout << res << endl;

}
