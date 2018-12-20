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
    LL N;
    cin >> N;

    vector<int> ans;
    int acu=0;
    int count = 1;
    int res;

    while(1)
    {
        int amari = N % LL(pow(2,count));
        dump(count)
        dump(pow(2,count))
        dump(amari)
        if(amari >= 0)
        {
            if(amari == (acu >= 0 ? acu : acu + LL(pow(2,count)))) res = 0;
            else res = 1;
        }
        else
        {
            if(amari+LL(pow(2,count)) == (acu >= 0 ? acu : acu + LL(pow(2,count)))) res = 0;
            else res = 1;
        }
        dump(res)
        acu += res * LL(pow(-2,count-1));
        dump(acu)
        ans.push_back(res);
        count++;

        if(acu == N) break;
        //if(count == 30) break;

    }

    for(auto i = 0; i < ans.size(); i++)
    {
        cout << ans[ans.size()-i-1];
    }
    cout << endl;
}
