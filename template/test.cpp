#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

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

int main(int argc, char const *argv[])
{
    vector<int> myvector;
    for (int i = 1; i<10; ++i) {
        myvector.push_back(i * 10);
    }

    cout << "myVector = " << printVector(myvector) << endl;
    return 0;
}