#include <numeric>

// 総和 std::reduce(v.begin(), v.end())
template <class ContainerIterator, typename T>
[[nodiscard]] T get_sum(ContainerIterator first, ContainerIterator last,
                        T init = 0) {
    return std::reduce(first, last, init);
}

// 総積
template <class ContainerIterator, typename T>
[[nodiscard]] T get_prod(ContainerIterator first, ContainerIterator last,
                         T init = 1) {
    return std::reduce(first, last, init, [](T acc, T el) { return acc * el; });
}

// 順序付き総和
template <class ContainerIterator, typename T>
[[nodiscard]] T get_sum_in_order(ContainerIterator first,
                                 ContainerIterator last, T init = 0) {
    return std::accumulate(first, last, init);
}

// 順序付き総積
template <class ContainerIterator, typename T>
[[nodiscard]] T get_prod_in_order(ContainerIterator first,
                                  ContainerIterator last, T init = 1) {
    return std::accumulate(first, last, init,
                           [](T acc, T el) { return acc * el; });
}