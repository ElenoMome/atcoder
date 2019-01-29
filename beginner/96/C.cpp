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

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};


//void dfs(int x, int y)
//{
    //int nx,ny;
    //O[x][y] = 0; //今いるところをゼロに
    //REP(i,4)
    //{
        //nx = x + dx[i];
        //ny = y + dy[i];
        //if(0 <= nx && nx <= H && 0 <= ny && ny <= W)
        //{
            //dfs(nx, ny);
        //}
    //}
//}

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int H,W;
    cin >> H >> W;

    int O[H][W];

    REP(i,H)
    {
        string s;
        cin >> s;
        REP(j,W)
        {
            if(s[j] == '.') O[i][j] = 0;
            else O[i][j] =1;
        }
    }
    bool ok = 1;

    REP(i,H)
    {
        REP(j,W)
        {
            if(O[i][j] == 1)
            {
                bool check = 0;
                REP(k,4)
                {
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if(0 <= nx && nx < H && 0 <= ny && ny < W)
                    {
                        if(O[nx][ny] == 1) check = 1;
                    }
                }
                if(check == 0) ok = 0;
            }
        }
    }

    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;





}
