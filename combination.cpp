
#include <iostream>
constexpr long long MOD = 1'000'000'007;  // log(MOD) ~ 30

/* 𝑶(min(r,n-r) log(MOD)) */
[[nodiscard]] long long comb(long long n, long long r) {
    //--------Valid Error------------------
    if (n <= 0 || r < 0) return 0LL;
    if (n < r) return 0LL;
    //-------------------------------------

    r = std::min(r, n - r);
    if (r == 0LL) return 1LL;
    if (r == 1LL) return n;

    // MOD上での逆元(モジュラ逆数)を求める
    int inverse[r + 1];
    for (long long i = 1LL; i <= r; ++i) {
        long long a = i, b = MOD, u = 1LL, v = 0LL, t;
        while (b > 0) {  // 𝑶(log(MOD))
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        inverse[i] = (u >= 0 ? u % MOD : (MOD - (-u) % MOD));
    }

    long long retVal = 1LL;
    for (long long i = 0LL; i < r; ++i) {
        retVal *= (n - i);  // retVal = n! / (n-r)!
        retVal %= MOD;
        retVal *= inverse[i + 1];  // retVal /= r!
        retVal %= MOD;
    }
    return retVal;
}

// test-----------------------------------------------
void abc145_d();  // nCr の n<=0 となりうる

int main(void) {
    abc145_d();
    return 0;
}

void abc145_d() {
    using lli = long long;
    lli x, y;
    std::cin >> x >> y;

    lli k = 2LL * x - y;
    if (k % 3LL) {
        std::cout << "0\n";
        return;
    }
    k /= 3LL;

    lli t = 2LL * y - x;
    if (t % 3LL) {
        std::cout << "0\n";
        return;
    }
    t /= 3LL;

    long long ans = comb(k + t, k);
    std::cout << ans << std::endl;

    return;
}

