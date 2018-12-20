#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>

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


int main() {
    // vector の初期化 10-90 の代入
    std::vector<int> myvector;
    for (int i = 1; i<10; ++i) {
        myvector.push_back(i * 10);
    }

    std::cout << "myVector = " << printVector(myvector) << std::endl;
    return 0;
}