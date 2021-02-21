#include <algorithm>
#include <iostream>

// worst 𝑶(log_2.2 max{a,b})
// a < b
template <typename T>
[[nodiscard]] T gcd(T a, T b) {
    // if (a > b) std::swap(a, b); // a<b 初回のみ
    return a ? gcd(b % a, a) : b;  // b%a < a
}

int main() {
    int a, b;
    std::cin >> a >> b;
    if (a > b) std::swap(a, b);
    std::cout << gcd(a, b) << '\n';
    return 0;
}