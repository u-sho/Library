#include <deque>
#include <vector>

// vector t を n進数 と見做したときの， t が表す値を返す
template <typename T>
unsigned long long t_as_n_ary(const std::vector<T> &t, const T n) {
    unsigned long long as_n_ary = 0ULL;
    unsigned long long pow_n_i  = 1ULL;
    for (const T &ti : t) {
        as_n_ary += ti * pow_n_i;
        pow_n_i *= (unsigned long long)n;
    }
    return as_n_ary;
}

// 変数 t を n進数 で表したときの，各桁の値を格納した vector を返す
template <typename T, typename U>
std::vector<U> t_to_n_ary(T t, const U n) {
    std::vector<U> n_ary;
    while (t) {
        n_ary.push_back(U(t % n));
        t /= n;
    }
    return n_ary;
}

// n進数どうしで比較するのは普通の比較演算子でOK
