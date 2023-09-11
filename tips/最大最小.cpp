#include <algorithm>
#include <iostream>
#include <vector>

#define ALL(v) (v).begin(), (v).end()

int main() {
    using namespace std;
    vector<int> v = {1, 2, -2, 900, 0};

    const auto [vmin, vmax] = minmax_element(ALL(v));
    cout << "イテレータ取得；" << *vmin << ", " << *vmax << endl;
    cout << "　　　　最大値：" << *max_element(ALL(v)) << endl;
    cout << "　　　　最小値：" << *min_element(ALL(v)) << endl;

#if __cplusplus > 201703L
    cout << "C++20 新機能\n";

    const auto m = ranges::minmax(v);
    cout << "　直接取得；" << m.min << ", " << m.max << endl;
    cout << "　　最大値：" << ranges::max(v) << endl;
    cout << "　　最小値：" << ranges::min(v) << endl;

    const auto it = ranges::minmax_element(v);
    cout << "　イテレータから：" << *it.min << ", " << *it.max << endl;
    cout << "　　　　　最大値：" << *ranges::max_element(v) << endl;
    cout << "　　　　　最小値：" << *ranges::min_element(v) << endl;
#endif

    return 0;
}