#include <iostream>
#include <string>
#include <vector>
 
using namespace std;
 
// 提出時はコメントアウト
#define DEBUG_
 
#ifdef DEBUG_
#define DEB
#else
// DEB と打つとデバッグ時以外はコメントアウトになる
#define DEB /##/
#endif
 
// 変数ダンプ用マクロ。デバッグ時以外は消滅する
// 引数はいくつでもどんな型でも可（ストリーム出力演算子があればOK）
#define dump(...) DEB cout<<"  "; \
cout<<#__VA_ARGS__<<" :["<<__LINE__<<":"<<__FUNCTION__<<"]"<<endl; \
cout<<"    "; \
dump_func(__VA_ARGS__)
 
// デバッグ用変数ダンプ関数
void dump_func() {
    cout << endl;
}
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
 
int main(void) {
    int num = 2;
    double pi = 3.14;
    string str = "str";
    char *chararr = "chararr";
    vector<int> vec{ 1,1,2,3 };
 
    dump(num, pi, str, chararr, vec);
 
    return 0;
}