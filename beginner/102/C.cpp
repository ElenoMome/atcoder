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
const int INF = 1e9+7;

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N;
    cin >> N;
    vector<LL> a(N);
    int min = INF;
    REP(i,N)
    {
        LL tmp;
        cin >> tmp;
        a[i] = tmp - i - 1;
        dump(a[i])
        if(a[i] < min) min = a[i];
    }
    if(min < 0)
    {
        REP(i,N)
        {
            a[i] -= min;
            dump(a[i])
        }
    }
    sort(a.begin(), a.end());
    int ave;
    ave = a[N/2];
    LL res = 0;
    REP(i,N)
    {
        res += abs(a[i] - ave);
    }
    cout << res << endl;

}
