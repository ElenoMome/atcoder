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
int a[1010], b[1010];
int A,B;
int dp[1010][1010];

int rec(int ta, int tb, int init)
{
    dump(ta)
    dump(tb)
    if(dp[ta][tb] != -1)
    {
        dump("hit!")
        return dp[ta][tb];
    } 

    bool turn = ((ta + tb) % 2) == init % 2; // 1:先手番 0:後手番
    if(turn) //先手番
    {
        if(ta == 0)
        {
            dp[ta][tb] = rec(0, tb-1, init) + b[B-tb];
            return rec(0, tb-1, init) + b[B-tb];
        }
        else if(tb == 0)
        {
            dp[ta][tb] = rec(ta-1, 0, init) + a[A-ta];
            return rec(ta-1, 0, init) + a[A-ta];
        }
        else
        {
            dp[ta][tb] = max(rec(ta-1,tb,init)+a[A-ta], rec(ta,tb-1,init)+b[B-tb]);
            return max(rec(ta-1,tb,init)+a[A-ta], rec(ta,tb-1,init)+b[B-tb]);
        }

    }
    else //後手番
    {
        if(ta == 0)
        {
            dp[ta][tb] = rec(0,tb-1,init);
            return rec(0,tb-1,init);
        }
        else if(tb == 0)
        {
            dp[ta][tb] = rec(ta-1,tb,init);
            return rec(ta-1,tb,init);
        }
        else
        {
            dp[ta][tb] = min(rec(ta-1,tb,init), rec(ta,tb-1,init));
            return min(rec(ta-1,tb,init), rec(ta,tb-1,init));
        }
    }
}

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    memset(dp, -1, sizeof(dp));
    dp[0][0] = 0;
    cin >> A >> B;

    REP(i,A)
    {
        cin >> a[i];
    }
    REP(i,B)
    {
        cin >> b[i];
    }

    dump(A) 
    dump(B)
    cout << rec(A,B,A+B) << endl;


}
