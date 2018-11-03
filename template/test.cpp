#include <iostream>
#include <vector>
using namespace std;
 
// vector出力
template<typename T>
ostream& operator << (ostream& os, vector<T>& vec) {
    os << "{";
    for (int i = 0; i<vec.size(); i++) {
        os << vec[i] << (i + 1 == vec.size() ? "" : ", ");
    }
    os << "}";
    return os;
}

// 再帰の終端。引数が0個の場合を担当。改行を出力。
void dump_func() {
    cout << endl;
}
// 可変長引数。引数が1つ以上存在する場合を担当。
// 最初の引数をHead、残りをTailとして切り離すことを再帰的に行う。
template <class Head, class... Tail>
void dump_func(Head&& head, Tail&&... tail)
{
    cout << head;
    if (sizeof...(Tail) == 0) {
        cout << " ";
    }
    else {
        cout << ", ";
    }
    dump_func(std::move(tail)...);
}
 
int main(){
  vector<int> A = {1,2,3,4};
  cout << A << endl;

   int num = 2;
    double pi = 3.14;
    string str = "str";
    char *chararr = "chararr";
    int arr[3] = {1,2,3};
 
    dump_func(num, pi, str, chararr, arr[1]);

  return 0;
}