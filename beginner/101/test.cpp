#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <functional>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#include <string>
#include <vector>
#include <bitset>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cstdlib>
#include <cassert>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <list>
#include <unordered_map>
 
using namespace std;
 
typedef long long LL;
typedef long double LD;
typedef pair<int, int> pii;
 
const LD eps = 1e-9;
const LD pi = acos(-1.0);
const LL inf = 1e+9;
 
#define mp make_pair
#define pb push_back
#define X first
#define Y second
 
#define dbg(x) { cerr << #x << " = " << x << endl; }
 
// extended template
#pragma comment(linker, "/STACK:36777216")
typedef vector<int> vi;
typedef vector<vi> vvi;
 
#define forn(i, n) for (int i = 0; i < n; ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
 
template<typename T> istream & operator >> (istream &, vector<T> &);
template<typename T> ostream & operator << (ostream &, const vector<T> &);
 
#define START clock_t _clock = clock();
#define END cerr << endl << "time: " << (clock() - _clock) / LD(CLOCKS_PER_SEC) << endl;
 
#define NAME "angle1"
 
 
LL S(LL x) {
	LL sum = 0;
	while (x) {
		sum += x % 10;
		x /= 10;
	}
	return sum;
}
 
void solve()
{
	/*
	vector <LL> tmp;
	for (int i = 1; i < 1000000; i++) {
		bool fl = 0;
		for (int j = i + 1; j < 1000000; j++) {
			if (i * S(j) > j * S(i)) {
				fl = 1;
				break;
			}
		}
		if (!fl)
			tmp.pb(i);
	}
	*/
	LL k;
	cin >> k;
	LL start = 1;
	LL add = 1;
	for (int i = 0; i < k; i++) {
		cout << start << endl;
		while (LD(start + add) / S(start + add) > LD(start + 2 * add) / S(start + 2  *add)) {
			add *= 10;
		}
		start += add;
	}
	
}
 
int main()
{
 
	//START
	//freopen(NAME ".in", "r", stdin); freopen(NAME ".out", "w", stdout);
	//freopen("input.txt", "r", stdin); // freopen("output.txt", "w", stdout);
	solve();
 
 
	//END		 
	return 0;
}
/*******************************************
*******************************************/
 
template<typename T> istream & operator >> (istream &is, vector<T> &v)
{
	forn(i, v.size())
		is >> v[i];
	return is;
}
template<typename T> ostream & operator << (ostream &os, const vector<T> &v)
{
	forn(i, v.size())
		os << v[i] << " ";
	return os;
}
#endif