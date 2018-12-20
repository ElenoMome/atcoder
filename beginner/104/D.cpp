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

    string S;
    cin >> S;
    int length = S.length();

    LL pow3mod[length+1];
    pow3mod[0] = 1;
    FOR(i,1,length+1)
    {
        pow3mod[i] = (pow3mod[i-1] * 3) % MOD;
    }
    LL ABC=0,BC=0,C=0;
    int hatena_count = 0;
    for(int i = length - 1; i >= 0; i--)
    {
        if(S[i] == 'A')
        {
            ABC = (ABC + BC) % MOD;
        }
        if(S[i] == 'B')
        {
            BC = (BC + C) % MOD;
        }
        if(S[i] == 'C')
        {
            C = (C + pow3mod[hatena_count]) % MOD;
        }
        if(S[i] == '?')
        {
            ABC = (3 * ABC + BC) % MOD;
            BC = (3 * BC + C) % MOD;
            C = (3 * C + pow3mod[hatena_count]) % MOD;
            hatena_count++;
        }
    }
    cout << ABC << endl;

}
