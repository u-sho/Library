#include <array>
#include <cstdio>  // std:: scanf
#include <deque>
#include <forward_list>
#include <iostream>  // std::cin
#include <list>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#define YES "Y"
#define NO "N"

// scanfの簡略化(std::stringとboolのみstd::cinで妥協)

// 符号付き整数
int scan(short &x) { return scanf("%hd", &x); }
int scan(int &x) { return scanf("%d", &x); }
int scan(long &x) { return scanf("&ld", &x); }
int scan(long long &x) { return scanf("%lld", &x); }

// 符号なし整数
int scan(unsigned short &x) { return scanf("%hu", &x); }
int scan(unsigned int &x) { return scanf("%u", &x); }
int scan(unsigned long &x) { return scanf("%lu", &x); }
int scan(unsigned long long &x) { return scanf("%llu", &x); }
int scan(std::size_t &x) { return scanf("%zd", &x); }

// 実数
int scan(float &x) { return scanf("%f", &x); }
int scan(double &x) { return scanf("%lf", &x); }
int scan(long double &x) { return scanf("%Lf", &x); }  // no tested

// 文字
int scan(char &x) { return scanf("%c", &x); }
int scan(wchar_t &x) { return scanf("%lc", &x); }
int scan(unsigned char &x) { return scanf("%c", &x); }

// 文字列と真偽値　std::cin.tie(nullptr);
int scan(std::string &x) { return ((std::cin >> x) ? 1 : -1); }
int scan(bool &x) {
    std::string s;
    int p = scan(s);
    if (p < 0) return p;
    if (s == YES) {
        x = true;
        return p;
    }
    if (s == NO) {
        x = false;
        return p;
    }
    return -1;
}

// 多変数
template <typename T, class... Args>
int scan(const T &x, const Args &... a) {
    int p = scan(x);
    if (p < 0) return p;  // assert使った方がいいのかな。。。？
    return p + scan(a...);
}

// pair
template <typename T1, typename T2>
int scan(const std::pair<T1, T2> &p) {
    int f = scan(p.first);
    if (f < 0) return f;  // assert使った方がいいのかな。。。？
    int s = scan(p.second);
    if (s < 0) return s;  // assert使った方がいいのかな。。。？
    return f + s;
}

// 以下コンテナ

// 汎用配列
template <typename T, std::size_t N>
int scan(const std::array<T, N> &a) {
    int res = 0;
    for (T &ae : a) {
        int p = scan(ae);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int scan(const std::vector<T> &v) {
    int res = 0;
    for (T &ve : v) {
        int p = scan(ve);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int scan(const std::deque<T> &d) {
    int res = 0;
    for (T &de : d) {
        int p = scan(de);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int scan(const std::list<T> &l) {
    int res = 0;
    for (T &le : l) {
        int p = scan(le);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int scan(const std::forward_list<T> &f) {
    int res = 0;
    for (T &fe : f) {
        int p = scan(fe);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}

// map
template <typename Key, typename T>
int scan(const std::map<Key, T> &m) {
    int res = 0;
    for (T &me : m) {
        int p = scan(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename Key, typename T>
int scan(const std::multimap<Key, T> &m) {
    int res = 0;
    for (T &me : m) {
        int p = scan(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename Key, typename T>
int scan(const std::unordered_map<Key, T> &m) {
    int res = 0;
    for (T &me : m) {
        int p = scan(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename Key, typename T>
int scan(const std::unordered_multimap<Key, T> &m) {
    int res = 0;
    for (T &me : m) {
        int p = scan(me);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}

// set
template <typename T>
int scan(const std::set<T> &s) {
    int res = 0;
    for (T &se : s) {
        int p = scan(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int scan(const std::multiset<T> &s) {
    int res = 0;
    for (T &se : s) {
        int p = scan(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int scan(const std::unordered_set<T> &s) {
    int res = 0;
    for (T &se : s) {
        int p = scan(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
template <typename T>
int scan(const std::unordered_multiset<T> &s) {
    int res = 0;
    for (T &se : s) {
        int p = scan(se);
        if (p < 0) return p;  // assert使った方がいいのかな。。。？
        res += p;
    }
    return res;
}
