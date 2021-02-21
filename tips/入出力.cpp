#include <iomanip>  // setprecision
#include <iostream>
#include <vector>

// std::pairの入出力
template <typename T1, typename T2>
std::istream &operator>>(std::istream &is, std::pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
std::ostream &operator<<(std::ostream &os, const std::pair<T1, T2> &p) {
    os << p.first << " " << p.second;
    return os;
}

// std::vectorの入出力
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        // os << v.at(i) << (i + 1 != v.size() ? " " : ""); // 空白区切り
        os << v.at(i) << "\n";  // 改行区切り
    }
    return os;
}

int main() {
    // cin で flushしない
    std::cin.tie(nullptr);

    // cstdioの入出力関数とのbufferの同期を切る
    std::ios::sync_with_stdio(false);

    // 指数表記をやめて小数表記にする
    std::cout << std::fixed;

    // 小数表記をやめて指数表記にする
    // std::cout << std::scientific;

    // 出力精度を指定する
    std::cout << std::setprecision(10);

    // 標準エラー出力でも設定できる
    std::cerr << std::fixed << std::setprecision(10);
}