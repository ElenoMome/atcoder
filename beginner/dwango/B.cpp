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

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N,K;
    cin >> N >> K;
    vector<LL> a(N);
    REP(i,N)
    {
        cin >> a[i];
    }

    LL sum[N*(N+1)/2];
    int l = 0;
    FOR(x,0,N)
    {
        FOR(y,x,N)
        {
            sum[l] = accumulate(a.begin() + x, a.begin() + y + 1, 0);
            dump(sum[l])
            l++;
        }
    }
    LL res = 0;
    for(int i = 40; i >= 0; i--)
    {
        LL add = 1LL << i;
        dump(add)
        int counter = 0;
        REP(j,N*(N+1)/2)
        {
            dump(res + add)
            dump(sum[j])
            dump((res + add) & sum[j])
            if(((res + add) & sum[j]) == res + add) counter++;
        }
        dump(counter)
        if(counter >= K) res += add;
    }

    cout << res << endl;


}
