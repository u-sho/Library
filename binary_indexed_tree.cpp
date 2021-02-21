#include <iostream>
#include <vector>

/**
 * T: int, long, long long, ModInt
 * std::stringを使いたい場合は全部int等に変換すること
 */
template <typename T>
class BIT {
    // 1-indexed
    std::vector<T> data;
    std::size_t size;

   public:
    BIT(const std::size_t &n, const T &value = 0) {
        data.assign(n + 1UL, value);
        size = n;
    }

    // add value to idx-th
    void add(const std::size_t &idx, const T &value = 1) {
        for (std::size_t i = idx; i <= size; i += i & (~i + 1UL)) {  // LSB
            data.at(i) += value;
        }
    }

    // sum of [1, idx]
    [[nodiscard]] T sum(const std::size_t &idx) const {
        T res = 0;
        for (std::size_t i = idx; i > 0UL; i -= i & (~i + 1UL)) {  // LSB
            T d = data.at(i);                                      // cast
            res += d;
        }
        return res;
    }

    // sum of [first, last]
    [[nodiscard]] T sum(const std::size_t &first,
                        const std::size_t &last) const {
        T res = sum(last) - sum(first - 1UL);  // cast
        return res;
    }

    [[nodiscard]] std::size_t getSize() const { return size; }  // debug用
    void print() const {
        std::cout << "size: " << size << "\n";
        for (std::size_t i = 0UL; i < size; i++) {
            std::cout << data.at(i) << (i + 1 != size) ? " " : "\n";
        }
        return;
    }
};
