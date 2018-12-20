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
    LL N,X;
    cin >> N >> X;

    LL laynum[N];
    laynum[0] = 1;
    FOR(i,1,N+1)
    {
        laynum[i] = laynum[i-1] * 2 + 3;
    }

    LL paty[N];
    paty[0] = 1;
    FOR(i,1,N+1)
    {
        paty[i] = paty[i-1] * 2 + 1;
    }

    LL res = 0;

    for(int level = N; level >= 0; level--)
    {
        dump(level) 
        dump(X)
        dump(laynum[level])
        dump(res)
        if(X == laynum[level])
        { 
            dump("sec1")
            res += paty[level];
            break;
        }
        if(X == (laynum[level] + 1)/2)
        {
            dump("sec2")
            res += (paty[level]+1) / 2;
            break;
        }
        if(X == 1)
        {
            dump("sec3")
            //res += ;
            break;
        }


        if(X > (laynum[level] + 1)/2)
        {

            res += (paty[level] + 1) / 2;
            X = X - (laynum[level] + 1)/2;
        }
        else if(X < (laynum[level] + 1)/2)
        {
            X = X - 1;
        }
    }

    cout << res << endl;

}
