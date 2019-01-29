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
    string s;
    cin >> s;
    int n;
    n = SZ(s);
    if(s[0] == '0' || s[n-1] == '1')
    {
        cout << -1 << endl;
        return 0;
    }
    bool ng = 0;
    FOR(i,1,n/2 + 1)
    {
        if(s[i] != s[n-2-i])
        {
            ng = 1;
            break;
        }
    }
    if(ng)
    {
        cout << -1 << endl;
        return 0;
    }

    cout << "1 2" << endl;
    int parent = 2;

    FOR(i,1,n-1)
    {
        if(s[i] == '1')
        {
            cout << parent << " " << i+2 << endl;
            parent = i+2;
        }
        else
        {
            cout << parent << " " << i+2 << endl;

        }

    }

}
