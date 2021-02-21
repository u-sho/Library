#include <algorithm>
#include <vector>

// SORT(a, <) で昇順， SORT(a, >) で降順
#define SORT(a, r)                    \
    std::sort((a).begin(), (a).end(), \
              [](auto const& x, auto const& y) { return x r y; })

#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rend(), (a).rbegin()

int main() {
    std::vector<int> t{8, 2, -2, 2};

    SORT(t, <);  // -1, 2, 2, 8
    SORT(t, >);  // 8, 2, 2, -1

    std::sort(ALL(t));   // -1, 2, 2, 8
    std::sort(RALL(t));  // 8, 2, 2, -1
}