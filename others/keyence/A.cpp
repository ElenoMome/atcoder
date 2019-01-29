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
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	

    int counter[4];
    REP(i,4)
    {
        counter[i] = 0;
    } 

    REP(i,4)
    {
        int tmp;
        cin >> tmp;
        if(tmp == 1)
        {
            counter[0] = 1;
        }

        if(tmp == 4)
        {
            counter[1] = 1;
        }

        if(tmp == 7)
        {
            counter[2] = 1;
        }

        if(tmp == 9)
        {
            counter[3] = 1;
        }
    }

    if(counter[0] && counter[1] && counter[2] && counter[3])
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

}