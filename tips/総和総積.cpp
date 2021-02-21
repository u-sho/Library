#include <numeric>

// 総和
template <class ContainerIterator, typename T>
[[nodiscard]] T get_sum(ContainerIterator first, ContainerIterator last,
                        T init = 0) {
    return std::accumulate(first, last, init);
}

// 総積
template <class ContainerIterator, typename T>
[[nodiscard]] T get_prod(ContainerIterator first, ContainerIterator last,
                         T init = 1) {
    return std::accumulate(first, last, init,
                           [](T acc, T el) { return acc * el; });
}