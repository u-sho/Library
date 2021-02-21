constexpr int mod = 1'000'000'007;

template <typename T>
[[nodiscard]] T modPow(const T p, const T e) {
    if (e == 0) return 1;
    if (e == 1) return p % mod;

    if (e & 1) return (p * modPow(p, e - 1) % mod);
    T p_pow_half_e = modPow(p, e >> 1);
    return p_pow_half_e * p_pow_half_e % mod;
}

template <typename T>
[[nodiscard]] T llPow(const T p, const T e) {
    if (e == 0) return 1;
    if (e == 1) return p;
    if (e == 2) return p * p;

    if (e % 2) return p * llPow(p, e - 1);
    T p_pow_half_e = llPow(p, e / 2);
    return p_pow_half_e * p_pow_half_e;
}
