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

int nth_bit(LL num, int n)
{
    return (num >> n) & 1;
}

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int D,G;
    cin >> D >> G;
    VI p(D);
    VI c(D);
    REP(i,D)
    {
        cin >> p[i] >> c[i];
    }
    VI s(D);
    REP(i,D)
    {
        s[i] = (i+1) * 100 * p[i] + c[i];
    }
    int res = 10000000;

    REP(i,pow(2,D))
    {
        int sumpoint = 0;
        int sumcount = 0; 
        bool flag = 0;
        int incom;
        REP(j,D)
        {
            if(nth_bit(i,j) == 1)
            {
                sumpoint += s[D-1-j];
                sumcount += p[D-1-j];
            }
            else
            {
                if(!flag)
                {
                    incom = j;
                    flag = 1;
                }
            }
        }

        if(sumpoint >= G)
        {
            if(res > sumcount) res = sumcount;
        }
        else
        {
            int add = ((G - sumpoint)+((D-incom)*100) - 1) / ((D - incom)*100);
            if(add < p[D-1-incom])
            {
                sumcount += add;
                if(res > sumcount) res = sumcount;
            }
        }
    }
    cout << res << endl;

}
