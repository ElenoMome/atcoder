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
    int N,C;
    scanf("%d %d", &N, &C);
    int D[C][C];
    int x[N][N];
    REP(i,C)
    {
        REP(j,C)
        {
            // D[i][j]はiからjに色を変えたときの違和感
            int tmp;
            scanf("%d", &tmp);
            D[i][j] = tmp;
        }
    }

    REP(i,N)
    {
        REP(j,N)
        {
            int tmp;
            scanf("%d", &tmp);
            x[i][j] = tmp - 1;
        }
    }

    LL min_score = LINF;

    LL costmemo[3][C];
    REP(i,3)
    {
        REP(j,C)
        {
            costmemo[i][j] = 0;
        }
    }


    REP(i,C)
    {
        REP(l,N)
        {
            REP(m,N)
            {
                if((l+m)%3 == 0) costmemo[0][i]+= D[x[l][m]][i];
                if((l+m)%3 == 1) costmemo[1][i]+= D[x[l][m]][i];
                if((l+m)%3 == 2) costmemo[2][i]+= D[x[l][m]][i];
            }
        }
    }


    REP(i,C)
    {
        REP(j,C)
        {
            if(j == i) continue;
            REP(k,C)
            {
                if(k == i || k == j) continue;
                LL score = 0;

                score = costmemo[0][i] + costmemo[1][j] + costmemo[2][k];

                if(score < min_score) min_score = score;

            }
        }
    }
    cout << min_score << endl;

}
