#include <iostream>
#include <string>

using namespace std;


char convert(char k)
{
    if(k=='1')
    {
        return '9';
    }
    if(k=='9')
    {
        return '1';
    }
}

int main()
{
    string str;
    cin >> str;

    for(int i = 0; i < 3; i++)
    {
    cout << convert(str[i]);
    }
    cout << endl;

}
