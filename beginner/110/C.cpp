#define rep(i, n) for(int i = 0; i < (int)(n); i++) //定番のn回繰り返しを省略
#define SZ(x) ((int)(x).size()) //unsignedのサイズをint型に変換
#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 

using namespace std;
 

//ここから書き始める
int main(int argc, char const *argv[])
{
	string s,t;
	int ato[26], mae[26];
	int flag = 0;

	cin >> s >> t;

	int strleng = SZ(t);

	rep(i, 26)
	{
		ato[i] = -1;
		mae[i] = -1;
	}


	rep(i, strleng)
	{
		int cas_a = s[i] - 'a';
		int cas_b = t[i] - 'a';
		if(ato[cas_a] != -1 || mae[cas_b] != -1)
		{
			if(ato[cas_a] != cas_b || mae[cas_b] != cas_a)
			{
				flag = 1;
				break;
			}

		}
		ato[cas_a] = cas_b;
		mae[cas_b] = cas_a;

	}

	cout << (flag == 0 ? "Yes" : "No") << endl;


    return 0;
}
