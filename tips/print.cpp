#include <array>
#include <cstdio>  // std::printf
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define YES "Yes\n"
#define NO "No\n"

// printf簡略化(C++20のstd::formatでstd::coutをもっと簡単に書ける)

// 符号付き整数
int print(const short &x) { return printf("%hd\n", x); }
int print(const int &x) { return printf("%d\n", x); }
int print(const long &x) { return printf("&ld\n", x); }
int print(const long long &x) { return printf("%lld\n", x); }

// 符号なし整数
int print(const unsigned short &x) { return printf("%hu\n", x); }
int print(const unsigned int &x) { return printf("%u\n", x); }
int print(const unsigned long &x) { return printf("%lu\n", x); }
int print(const unsigned long long &x) { return printf("%llu\n", x); }
int print(const std::size_t &x) { return printf("%zd\n", x); }

// 実数
int print(const float &x) { return printf("%.8f\n", x); }
int print(const double &x) { return printf("%.16lf\n", x); }
int print(const long double &x) { return printf("%.32Lf\n", x); }  // no tested

// 文字と文字列
int print(const char &x) { return printf("%c\n", x); }
int print(const wchar_t &x) { return printf("%lc\n", x); }
int print(const unsigned char &x) { return printf("%c\n", x); }
int print(const std::string &x) { return printf("%s\n", x.c_str()); }

// 真偽値
int print(const bool &x) { return printf(x ? YES : NO); }

// 以下pair.first用
int print_s(const short &x) { return printf("%hd ", x); }
int print_s(const int &x) { return printf("%d ", x); }
int print_s(const long &x) { return printf("&ld ", x); }
int print_s(const long long &x) { return printf("%lld ", x); }
int print_s(const unsigned short &x) { return printf("%hu ", x); }
int print_s(const unsigned int &x) { return printf("%u ", x); }
int print_s(const unsigned long &x) { return printf("%lu ", x); }
int print_s(const unsigned long long &x) { return printf("%llu ", x); }
int print_s(const std::size_t &x) { return printf("%zd ", x); }
int print_s(const float &x) { return printf("%.8f ", x); }
int print_s(const double &x) { return printf("%.16lf ", x); }
int print_s(const long double &x) { return printf("%.32Lf ", x); }
int print_s(const char &x) { return printf("%c ", x); }
int print_s(const wchar_t &x) { return printf("%lc ", x); }
int print_s(const unsigned char &x) { return printf("%c ", x); }
int print_s(const std::string &x) { return printf("%s ", x.c_str()); }
int print_s(const bool &x) { return printf(x ? YES : NO); }  // これだけ改行

// 多変数
template <typename T, class... Args>
int print(const T &x, const Args &... a) {
    int p = print(x);
    if (p < 0) return p;  // assert使った方がいいのかな。。。？
    return p + print(a...);
}

// pair
template <typename T1, typename T2>
int print(const std::pair<T1, T2> &p) {
    int f = print_s(p.first);
    if (f < 0) return f;  // assert使った方がいいのかな。。。？
    int s = print(p.second);
    if (s < 0) return s;  // assert使った方がいいのかな。。。？
    return f + s;
}

// 以下コンテナ

// 汎用配列
template <typename T, std::size_t N>
int print(const std::array<T, N> &a) {
    int res = 0;
    for (const T &ae : a) {
        int p = print(ae);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int print(const std::vector<T> &v) {
    int res = 0;
    for (const T &ve : v) {
        int p = print(ve);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int print(const std::deque<T> &d) {
    int res = 0;
    for (const T &de : d) {
        int p = print(de);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int print(const std::list<T> &l) {
    int res = 0;
    for (const T &le : l) {
        int p = print(le);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int print(const std::forward_list<T> &f) {
    int res = 0;
    for (const T &fe : f) {
        int p = print(fe);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}

// map
template <typename Key, typename T>
int print(const std::map<Key, T> &m) {
    int res = 0;
    for (const T &me : m) {
        int p = print(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename Key, typename T>
int print(const std::multimap<Key, T> &m) {
    int res = 0;
    for (const T &me : m) {
        int p = print(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename Key, typename T>
int print(const std::unordered_map<Key, T> &m) {
    int res = 0;
    for (const T &me : m) {
        int p = print(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename Key, typename T>
int print(const std::unordered_multimap<Key, T> &m) {
    int res = 0;
    for (const T &me : m) {
        int p = print(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}

// set
template <typename T>
int print(const std::set<T> &s) {
    int res = 0;
    for (const T &se : s) {
        int p = print(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int print(const std::multiset<T> &s) {
    int res = 0;
    for (const T &se : s) {
        int p = print(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int print(const std::unordered_set<T> &s) {
    int res = 0;
    for (const T &se : s) {
        int p = print(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int print(const std::unordered_multiset<T> &s) {
    int res = 0;
    for (const T &se : s) {
        int p = print(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
