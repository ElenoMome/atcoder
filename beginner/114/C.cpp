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
    int N;
    cin >> N;
    int max_digit = to_string(N).size(); //桁数
    int arr[3] = {3,5,7};
    LL seed = LL(pow(3,max_digit));
    int ans = 0;

    FOR(digit,1,max_digit+1)
    {
        FOR(i,0,LL(pow(3,digit)))
        {
            int num = i;
            int sum = 0;
            bitset<3> check;
            REP(j,digit)
            {
                sum = sum * 10 + arr[num % 3];
                check[num % 3] = true;
                num /= 3;
            }
            if(check.all() && sum <= N) {
                dump(sum)
                ans++;
            }
        }
    }
    cout << ans << endl;

}
