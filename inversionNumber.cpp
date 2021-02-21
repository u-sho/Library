// 転倒数 jsc2019_qual bなど
#include <climits>  // LLONG_MIN
#include <vector>

#include "./binary_indexed_tree.cpp"  // BIT

/**
 * T: int, long, long long, ModInt
 * std::string を用いる場合は int 等に変換する
 * 要素数 N と 要素の最大値M に対して 𝑶(N logM)
 * 最大で N^2 / 2 なので，たぶん long long で十分
 */
template <typename T>
long long inversionNumber(const std::vector<T> &v) {
    T v_max = 0;
    for (const T &ve : v) {
        if (v_max < ve) v_max = ve;
    }
    BIT<T> bit(v_max);

    long long res = 0LL;
    for (std::size_t i = 0UL; i < v.size(); ++i) {
        // bit.sum(): これまで出てきたうちで自分より小さい要素の数>=0
        long long sum = i - bit.sum(v.at(i));
        res += sum;
        bit.add(v.at(i));
    }
    return res;
}

// template <typename T>
// T inversionNumber(const std::vector<long long> &v) {
//     long long v_max = LLONG_MIN;
//     for (const long long &ve : v) {
//         if (v_max < ve) v_max = ve;
//     }
//     BIT<long long> bit(v_max);

//     T res = 0;
//     for (std::size_t i = 0UL; i < v.size(); ++i) {
//         T sum = i - bit.sum(v.at(i));
//         res += sum;
//         bit.add(v.at(i));
//     }
//     return res;
// }