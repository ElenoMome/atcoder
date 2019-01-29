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

const int MAX_N=1030;
double dp[MAX_N][MAX_N];
double R[MAX_N];

double rec(int i, int j)
{
    if(i == 0) return dp[i][j] = 1;
    if(dp[i][j] != 0) return dp[i][j];
    int l=((j>>(i-1))^1)<<(i-1);
    REP(k,(int)pow(2,i-1)){
        dp[i][j]+=(1/(1+pow(10,(R[l+k]-R[j])/400.0)))*rec(i-1,j)*rec(i-1,l+k);
    }

    return dp[i][j];

}


//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int K;
    cin>>K;
    REP(i,(int)pow(2,K))cin>>R[i];
    REP(i,(int)pow(2,K))cout<<rec(K,i)<<endl;
 

}

