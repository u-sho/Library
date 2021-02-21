#include <cmath>
#include <iostream>
#include <vector>

// https://qiita.com/drken/items/a14e9af0ca2d857dad23#4-%E7%B4%A0%E5%9B%A0%E6%95%B0%E5%88%86%E8%A7%A3

using PrimeFact     = std::pair<long long, int>;
using PrimeFactores = std::vector<PrimeFact>;

PrimeFactores prime_factorize(long long N) {
    PrimeFactores res;

    for (long long p = 2LL; p * p <= N; ++p) {
        if (N % p) continue;  // 素因数判定

        int ex = 0;  // 指数
        while (N % p == 0LL) {
            ++ex;
            N /= p;
        }

        res.push_back({p, ex});  // pow(p, ex)
    }
    if (N > 1LL) res.push_back({N, 1});  // 素因数判定 (N==0となることはない)

    return res;
}

int main() {
    long long N;
    std::cin >> N;

    const PrimeFactores& res = prime_factorize(N);
    std::cout << N << ":";
    for (const PrimeFact& p : res) {
        for (int i = 0; i < p.second; ++i) std::cout << " " << p.first;
    }
    std::cout << '\n';

    return 0;
}