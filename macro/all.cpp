#include <algorithm>
#include <vector>

#define ALL(v) (v).begin(), (v).end()
#define all(v, n) &(v)[0], &(v)[n]

#define RALL(v) (v).rend(), (v).rbegin()
// #define rall(v, n) &(v)[n],&(v)[0]

int main() {
    std::vector<int> t{8, 2, -2, 2};

    std::sort(ALL(t));   // -1, 2, 2, 8
    std::sort(RALL(t));  // 8, 2, 2, -1

    std::sort(all(t, 3));  // 2, 2, 8, -1
    // std::sort(rall(t, 3));  // 2, 8, 2, -1
}