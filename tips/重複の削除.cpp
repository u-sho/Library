#include <algorithm>  // sort, unique
#include <iostream>   // テスト
#include <string>     // テスト

/**
 * std::unique は
 * 1. 連続した要素のうち先頭以外の要素を後ろに持っていく
 * 2. 後ろに持っていった要素の値は未規定になる
 * 3. 後ろに持っていった要素の先頭のイテレータを返す
 */
/**
 * 3 2 2 1
 * sort-> 1 2 2 3
 * unique-> 1 2 3 x
 * erase-> 1 2 3
 */
template <class Container>
[[nodiscard]] Container deduplicate(Container v) {
    std::sort(begin(v), end(v));
    v.erase(std::unique(begin(v), end(v)), end(v));
    return v;
}

// tests----------------------------------------------------------------
void abc098_b();  // stringの重複削除

int main() {
    abc098_b();
    return 0;
}

void abc098_b() {
    using std::string;
    int n;
    std::cin >> n;
    string s;
    std::cin >> s;

    int ans = 0;
    for (int i = 1; i < n - 1; ++i) {
        string f = deduplicate(s.substr(0UL, i));
        string r = deduplicate(s.substr(i));

        int duplications = 0;
        for (char fc : f) {  // 𝑶(n * n/2 * n/2)
            // find は一致する要素を探してイテレータを返す
            if (r.find(fc) != string::npos) duplications++;
        }
        ans = std::max(ans, duplications);
    }

    std::cout << ans << "\n";
    return;
}