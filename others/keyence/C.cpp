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
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N;
    cin >> N;
    vector<LL> A(N), B(N);
    vector<LL> diff(N);

    LL Asum = 0;
    LL Bsum = 0; 
    REP(i,N)
    {
        cin >> A[i];
        Asum += A[i];
    }
    REP(i,N)
    {
        cin >> B[i];
        Bsum += B[i];
        diff[i] = A[i] - B[i];
    }

    if(Asum < Bsum) 
    {
        cout << -1 << endl;
        return 0;
    }

    sort(diff.begin(), diff.end());

    LL debtcount = 0;
    int ncount = 0;
    int pcount = 0; 
    for(auto u : diff)
    {
        if(u < 0)
        {
            debtcount += u;
            ncount++;
        }
        else break;
    }
    if(debtcount < 0)
    {

        for(int index = N - 1; index >= 0; index--)
        {
            debtcount += diff[index];
            pcount++;
            if(debtcount >= 0)
            {
                break;
            }
        }
    }

    dump(debtcount)

    cout << ncount + pcount << endl;



}
