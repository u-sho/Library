#include <bits/stdc++.h>
// using std::gcd;
using std::make_pair;
using std::max;
using std::min;
using std::pair;
using std::sort;
using std::string;
using std::vector;
using lli  = long long;
using ulli = unsigned lli;

// pairの入出力
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

// vectorの入出力
template <typename T>
std::istream &operator>>(std::istream &is, std::vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}
template <typename T>
std::ostream &operator<<(std::ostream &os, const std::vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i + 1 != v.size() ? " " : "");
    }
    return os;
}

// よく使う定数
// std::string ans[2] = {"No\n", "Yes\n"};
constexpr int MOD = 1'000'000'007;
// constexpr int MOD = 998'244'353;

// メイン
int main() {
    using std::cin;
    using std::cout;
    using std::endl;

    cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    cout << std::fixed << std::setprecision(10);

    /**/
    return 0;
}

using int64 = long long;

constexpr int64 infLL = LLONG_MAX;
constexpr int inf     = INT_MAX;

template <typename T = int64>
std::vector<T> make_v(size_t a) {
    return vector<T>(a);
}
template <typename T, typename... Ts>
auto make_v(size_t a, Ts... ts) {
    return vector<decltype(make_v<T>(ts...))>(a, make_v<T>(ts...));
}

template <typename T, typename V>
typename std::enable_if<std::is_class<T>::value == 0>::type fill_v(T &t,
                                                                   const V &v) {
    t = v;
}

template <typename T, typename V>
typename std::enable_if<std::is_class<T>::value != 0>::type fill_v(T &t,
                                                                   const V &v) {
    for (auto &e : t) fill_v(e, v);
}

template <typename F>
struct FixPoint : F {
    FixPoint(F &&f) : F(forward<F>(f)) {}

    template <typename... Args>
    decltype(auto) operator()(Args &&... args) const {
        return F::operator()(*this, forward<Args>(args)...);
    }
};

template <typename F>
inline decltype(auto) MFP(F &&f) {
    return FixPoint<F>{forward<F>(f)};
}