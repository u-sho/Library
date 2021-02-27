// abc193 c問題

#include <iostream>
#include <unordered_set>
using namespace std;
using lli = long long;

int main() {
    lli N;
    cin >> N;

    unordered_set<lli> s;
    for (lli i = 2; i * i <= N; ++i)
        for (lli i2 = i * i; i2 <= N; i2 *= i)
            s.insert(i2);  // 重複なく数え上げる

    cout << N - s.size() << "\n";
}
