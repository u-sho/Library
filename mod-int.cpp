#include <iostream>
constexpr int mod = 1'000'000'007;

// https://github.com/ei1333/library/blob/master/math/combinatorics/arbitrary-mod-int.cpp
// 少し変えてる
struct ModInt {
    int x;
    ModInt() : x(0) {}
    ModInt(long long y) : x(y >= 0 ? y % mod : (mod - (-y) % mod) % mod) {}

    ModInt &operator+=(const ModInt &p) {
        if ((x += p.x) >= mod) x -= mod;
        return *this;
    }
    ModInt &operator-=(const ModInt &p) {
        if ((x -= p.x) < 0) x += mod;
        return *this;
    }
    ModInt &operator*=(const ModInt &p) {
        x = (int)(1LL * x * p.x % mod);
        return *this;
    }
    ModInt &operator/=(const ModInt &p) {
        *this *= p.inverse();
        return *this;
    }

    ModInt operator-() const { return ModInt(-x); }
    ModInt operator+(const ModInt &p) const { return ModInt(*this) += p; }
    ModInt operator-(const ModInt &p) const { return ModInt(*this) -= p; }
    ModInt operator*(const ModInt &p) const { return ModInt(*this) *= p; }
    ModInt operator/(const ModInt &p) const { return ModInt(*this) /= p; }

    bool operator==(const ModInt &p) const { return x == p.x; }
    bool operator!=(const ModInt &p) const { return x != p.x; }

    [[nodiscard]] ModInt inverse() const {
        int a = x, b = mod, u = 1, v = 0, t;
        while (b > 0) {
            t = a / b;
            std::swap(a -= t * b, b);
            std::swap(u -= t * v, v);
        }
        return ModInt(u);
    }

    template <typename T>
    [[nodiscard]] ModInt pow(T n) const {
        if (n < 0) assert(false);
        ModInt ret(1), mul(x);
        while (n > 0) {
            if (n & 1) ret *= mul;
            mul *= mul;
            n >>= 1;
        }
        return ret;
    }

    friend std::ostream &operator<<(std::ostream &os, const ModInt &p) {
        return os << p.x;
    }
    friend std::istream &operator>>(std::istream &is, ModInt &a) {
        long long t;
        is >> t;
        a = ModInt(t);
        return is;
    }

    [[maybe_unused]] [[nodiscard]] static int get_mod() { return mod; }
};

// usage----------------------------
int main(void) {
    ModInt a, b;
    std::cin >> a >> b;
    std::cout << "     MOD = " << a.get_mod() << std::endl;
    std::cout << "   a + b = " << a + b << std::endl;
    std::cout << "   a - b = " << a - b << std::endl;
    std::cout << "   a * b = " << a * b << std::endl;
    std::cout << "   a / b = " << a / b << std::endl;
    std::cout << "pow(a,b) = " << a.pow(b.x) << std::endl;
    return 0;
}
