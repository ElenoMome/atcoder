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

const int MOD = 1e9+7;
const LL LINF = 1001002003004005006ll;
const int INF = 1001001001;

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int N,M;
    cin >> N >> M;
    VI A(N),B(M);
    VI C(N*M);
    REP(i,N)
    {
        cin >> A[i];
    }
    REP(i,M)
    {
        cin >> B[i];
    }

    REP(i,N*M) 
    {
        bool aflag = 0, bflag = 0;
        REP(j,N)
        {
            if(A[j] == i+1) 
            {
                if(aflag == 0)
                    aflag = 1;
                else
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }

        REP(j,M)
        {
            if(B[j] == i+1) 
            {
                if(bflag == 0)
                    bflag = 1;
                else
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }

        if(aflag == 1 && bflag == 1)
        {
            dump("A")
            dump(i)
            C[i] = 1;
        }
        else if(aflag == 1 && bflag == 0)
        {
            dump("B")
            dump(i)
            int counter = 0;
            REP(j,M) 
            {
                if(B[j] > i+1) counter++;
            }
            C[i] = counter;
        }
        else if(aflag == 0 && bflag == 1)
        {
            dump("C")
            dump(i)
            int counter = 0;
            REP(j,N) 
            {
                if(A[j] > i+1) counter++;
            }
            C[i] = counter;
        }
        else if(aflag == 0 && bflag == 0)
        {
            dump("D")
            dump(i)
            int counter1 = 0, counter2 = 0;
            REP(j,N)
            {
                if(A[j] > i+1) counter1++;
            }
            REP(j,M)
            {
                if(B[j] > i+1) counter2++;
            }
            C[i] = counter1 * counter2 - (N*M - (i+1));
        }
        
    }
    LL res = 1;

    REP(i,N*M)
    {
        dump(i)
        dump(C[i])
        res = (res * C[i]) % MOD;
    }
    cout << res << endl;



}
