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

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N;
    cin >> N;
    VI c(N);

    REP(i,N-1)
    {
        cin >> c[i];
    }

    LL acc_sum_l[N], acc_sum_r[N];
    acc_sum_l[0] = 0;
    acc_sum_r[0] = 0;

    FOR(i,1,N)
    {
        acc_sum_l[i] = acc_sum_l[i-1] + c[i-1];
        acc_sum_r[i] = acc_sum_r[i-1] + c[N-1-i];
        dump(acc_sum_l[i])
        dump(acc_sum_r[i])
    }

    int rec_l, rec_r, index_l, index_r;
    rec_l = 0;
    rec_r = 0;

    LL max_l[N], max_r[N];
    REP(i,N)
    {
        if(i != 0)
        {
            if(rec_l > c[i-1]) rec_l = c[i-1];
        }
        max_l[i] = acc_sum_l[i] - rec_l;
        dump(rec_l)
        dump(max_l[i])
    }
    for(int i = N-1; i >= 0; i--)
    {
        if(i == N-1) rec_r = c[N-1];
        if(rec_r > c[i]) rec_r = c[i];
        max_r[i] = acc_sum_r[N-1-i] - rec_r;
        dump(max_r[i])
    }
    REP(i,N)
    {
        cout << max(max_l[i], max_r[i]) << endl;
    }
    

}
