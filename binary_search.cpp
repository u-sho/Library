#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()

// 画面幅
using w_t = uint_fast64_t;

// 行数・画面高さ
using h_t = uint_fast32_t;

// 単語長
using l_t = uint_fast32_t;

/** カーソル位置 (line, column) */
struct Cursor {
    h_t line   = 1U;
    w_t column = 0U;
    w_t window_width;
    Cursor(const w_t W) : window_width(W){};

    /** 現在のカーソル位置に単語長 l の単語を（空白区切りで）追加 */
    Cursor& operator+=(const l_t& l) {
        if (column + l > window_width) {  // break line
            ++line;
            column = 0U;
        }
        column += l + 1U;  // add word (+space)
        return *this;
    }

    Cursor operator+(const l_t& l) { return (*this += l); }
};

/** abc319 D
 * `N` 単語からなる欧文を `M` 行以内で画面に表示するときの最小の画面幅 `W`
 * を求めたい．
 * ただし，`L` は単語長リストである．
 */
[[nodiscard]] w_t solve(const uint_fast32_t N, const h_t M,
                        const vector<l_t>& L) {
    // 最大単語長：1単語での改行を許したときの画面幅
    w_t maxL = ranges::max(L);

    // 1行に全単語を表示したときの画面幅（各単語間は空白を挿入）
    w_t maxW = reduce(ALL(L), w_t(N - 1U));

    // 画面幅を `W` としたときに `M` 行を超えてしまうか
    const auto is_over_M = [&L, &M](const w_t W) -> bool {
        Cursor cursor = accumulate(ALL(L), Cursor(W));
        return (cursor.line > M);
    };

    // `M` 行を超えない最小の画面幅 `W` を `[maxL, maxW]` の範囲で二分探索
    // views::iota(l,r) は遅延評価で l から r までインクリメントした range
    w_t minW = *ranges::partition_point(views::iota(maxL, maxW), is_over_M);
    return minW;
}

int main() {
    cin.tie(nullptr);
    ios::sync_with_stdio(false);

    uint_fast32_t N, M;
    cin >> N >> M;
    vector<l_t> L(N);
    for (l_t& Li : L) cin >> Li;

    cout << solve(N, M, L) << '\n';

    return 0;
}
