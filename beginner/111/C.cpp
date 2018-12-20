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
const int maxn = (1e5) + 10;

//ここから書き始める
int main(int argc, char const *argv[])
{
    cin.tie(0);
    ios::sync_with_stdio(false);	
    int n;
    cin >> n;
    int odd[maxn],even[maxn];

    REP(i,maxn)
    {
        odd[i] = 0;
        even[i] = 0;
    }

    FOR(i,1,n+1)
    {
        int temp;
        cin >> temp;
        if(i%2 != 0) odd[temp]++;
        else even[temp]++;
    }
    int maxcount1_odd = 0; int maxcount2_odd = 0;
    int maxcount1_even = 0; int maxcount2_even = 0;
    int num1_odd, num2_odd;
    int num1_even, num2_even;

    //first
    REP(i,maxn)
    {
        //odd
        if(odd[i] > maxcount1_odd)
        {
            maxcount1_odd = odd[i];
            num1_odd = i;
        }
        //even

        if(even[i] > maxcount1_even)
        {
            maxcount1_even = even[i];
            num1_even = i;
        }
    }

    odd[num1_odd] = 0;
    even[num1_even] = 0;
    //second

    REP(i,maxn)
    {
        //odd
        if(odd[i] > maxcount2_odd)
        {
            maxcount2_odd = odd[i];
            num2_odd = i;
        }
        //even

        if(even[i] > maxcount2_even)
        {
            maxcount2_even = even[i];
            num2_even = i;
        }
    }
    dump(num1_odd)
    dump(num2_odd)
    dump(num1_even)
    dump(num2_even)

    if(num1_odd != num1_even)
    {
        cout << n - maxcount1_odd - maxcount1_even << endl;
    }
    else
    {
        cout << n - max(maxcount1_odd + maxcount2_even, maxcount1_even + maxcount2_odd) << endl;
    }
}
