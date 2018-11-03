#define rep(i, n) for(int i = 0; i < (int)(n); i++) //n回繰り返しを省略
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#define dump(x) cerr<<#x<<"="<<x<<endl
 
using namespace std;


vector<pair<long long, long long> > prime_factorize(long long n) {
    vector<pair<long long, long long> > res;
    for (long long p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        res.push_back(make_pair(p, num));
    }
    if (n != 1) res.push_back(make_pair(n, 1));
    return res;
}
const int MAX = 210000;
const int MOD = 1000000007;


 
long long fac[MAX], finv[MAX], inv[MAX];
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAX; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
long long COM(int n, int k){
    if(n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n-k] % MOD) % MOD;
} 
long long nCr(int n, int r)
{
    long long ans = 1;

    for(int i = 0; i < r; i++)
    {
        ans *= n;
        n--;
    }
    for(int i = 0; i < r; i++)
    {
        ans /=  i+1;
    }
    return ans;

}

//ここから書き始める
int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;

	//素因数分解
	auto vec = prime_factorize(m);

	long long res = 1;
	COMinit();

	for(auto pa : vec)
	{
		int num = pa.second;
		long long tmp = COM(num+n-1, n-1);
		res = (res * tmp) % 1000000007;
	}


	cout << res << endl;
}
