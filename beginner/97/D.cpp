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
#define pb push_back

typedef long long LL; 
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;

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

struct UnionFind{
    vector<int> par,rank;
    UnionFind(int N){
        par.assign(N,0);
        rank.assign(N,0);
        REP(i,N) par[i]=i;
    }
    int find(int x){
        if(par[x]==x) return x;
        return par[x]=find(par[x]);
    }
    bool same(int x,int y){
        return find(x)==find(y);
    }
    void unite(int x,int y){
        x=find(x),y=find(y);
        if(x==y) return;
        if(rank[x]<rank[y]) swap(x,y);
 
        //x becomes root
        par[y]=x;
        if(rank[x]==rank[y]) rank[x]++;
    }
};


//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N,M;
    cin >> N >> M;
    VI p(N);
    REP(i,N)
    {
        cin >> p[i];
        p[i]--;
    }
    UnionFind UF(N);
    REP(i,M)
    {
        int x,y;
        cin >> x >> y;
        x--; y--;
        UF.unite(x,y);
    }
    int ans = 0;
    REP(i,N)
    {
        if(UF.find(i) == UF.find(p[i])) ans++;
    }
    cout << ans << endl;

}
