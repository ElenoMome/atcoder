#include <iostream>

using namespace std;

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

int main()
{
    int n,r;
    cin >> n >> r;
    cout << nCr(n,r);
}
