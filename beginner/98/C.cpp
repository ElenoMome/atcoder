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
    string S;
    cin >> S;

    int left_cost[N];
    int right_cost[N];
    int first = 0;
    FOR(i,1,N)
    {
        if(S[i] == 'E') first++;
    }
    right_cost[0] = first;
    left_cost[0] = 0;

    FOR(i,1,N)
    {
        if(S[i] == 'E')
        {
            right_cost[i] = right_cost[i-1] - 1;
        }
        else
        {
            right_cost[i] = right_cost[i-1];
        }

        if(S[i-1] == 'W') left_cost[i] = left_cost[i-1] + 1;
        else left_cost[i] = left_cost[i-1];

    }
    int total_cost[N];
    int min = MOD;
    REP(i,N)
    {
        total_cost[i] = left_cost[i] + right_cost[i];
        if(total_cost[i] < min) min = total_cost[i];
    }

    cout << min << endl;
}
