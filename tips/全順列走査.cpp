#include <algorithm>
#include <vector>
int main() {
    std::vector<int> v;
    std::sort(v.begin(), v.end());
    do {
        // ここでいろいろする
    } while (std::next_permutation(v.begin(), v.end()));
    /**
     * next_permutation は
     * 1. 辞書順で次に大きいものに並べ替えてtrueを返す
     * 2. 辞書順最大のときは，最小に並べ替えてfalseを返す
     */
}
