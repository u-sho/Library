#include <cmath>
#include <iostream>
#include <vector>

// 参考：https://qiita.com/drken/items/a14e9af0ca2d857dad23#4-素因数分解

using PrimeFactor  = std::pair<uint64_t, unsigned>;
using PrimeFactors = std::vector<PrimeFact>;

PrimeFactors prime_factorize(uint64_t N) {
    PrimeFactors res;

    for (uint64_t p = 2ULL; p * p <= N; ++p) {
        if (N % p) continue;  // 素因数判定

        unsigned ex = 0U;  // 指数
        while (N % p == 0ULL) {
            ++ex;
            N /= p;
        }

        res.push_back({p, ex});  // pow(p, ex)
    }
    if (N > 1ULL) res.push_back({N, 1U});  // 素因数判定 (N==0となることはない)

    return res;
}

int main() {
    long long N;
    std::cin >> N;

    const PrimeFactors& res = prime_factorize(N);
    std::cout << N << ":";
    for (const PrimeFact& p : res) {
        for (int i = 0; i < p.second; ++i) std::cout << " " << p.first;
    }
    std::cout << '\n';

    return 0;
}