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


typedef long long LL; 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL,LL> PLL;


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
    int n,k;
    cin >> n >> k;
    VI f(n+10);
    priority_queue<PLL> q; //今選択していない集合
    priority_queue<PLL, vector<PLL>, greater<PLL>> q2; //今選択している集合
    for(int i = 0; i < n; i++)
    {
        int t,d;
        cin >> t >> d;
        q.push(PLL(d,t));
    }
    int co = 0; //??
    LL x = 0, s = 0, ans = 0;
    while(co < k)
    {
        PLL p = q.top(); q.pop(); // qの一番でかい順に取り出す
        q2.push(p); //取り出したのをq2に入れる
        s += p.first; //おいしさプラス
        if(f[p.second] == 0) x++;
        f[p.second]++;
        co++;
    }
    ans = s + x*x;
    while(!q.empty()) //ネタの種類を増やしていくフェーズ
    {
        PLL p = q.top(); q.pop();
        if(f[p.second]) continue; //すでに使われていたらスキップ
        LL m = -1;
        while(!q2.empty())
        {
            PLL p2 = q2.top(); q2.pop(); //q2の一番小さいやつを取り出す　
            if(f[p2.second] > 1) //2個以上使われてたら採用
            {
                f[p2.second]--;
                m = p2.first; //取り出すやつのおいしさ
                break;
            }
        }
        if(m==-1) break;
        x++;
        f[p.second]++;
        s += p.first;
        s -= m;
        ans = max(ans,s+x*x);

    }
    cout << ans << endl;


}
