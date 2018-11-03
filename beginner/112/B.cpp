#define rep(i, n) for(int i = 0; i < (int)(n); i++) //定番のn回繰り返しを省略
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
int MAX_N = 300;


//ここから書き始める
int main(int argc, char const *argv[])
{
	int N,T;
	int c[MAX_N],t[MAX_N];


	cin >> N >> T;

	pair<int, int> kouho[N];
	rep(i,N)
	{
		cin >> c[i];
		cin >> t[i];
		kouho[i].first = c[i];
		kouho[i].second = t[i];

	}

	sort(kouho, kouho + N);
	rep(i, N)
	{
		if(kouho[i].second <= T)
		{
			cout << kouho[i].first << endl;
			break;
		}

		if(i == N - 1) cout << "TLE" << endl;
	}



    return 0;
}
