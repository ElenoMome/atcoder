#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	int ans;

	if(N%111 != 0)
	{
		ans = ((N / 111) + 1) * 111; 
	}
	else
	{
		ans = N;
	}

	cout << ans << endl;

	return 0;
}