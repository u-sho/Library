#include <vector>

// マージの工夫をしていないため，クエリは 𝑶(log n)

template <class Node>
class UnionFind {
    std::vector<Node> parent;

  public:
    /* サイズ n の素集合を作成: o(n) */
    UnionFind(const std::size_t &n) : parent(n) {
        for (std::size_t i = 0; i < n; i++) parent[i] = Node(i);
    }

    /* ノード x が属する木の根を返す：𝑶(log n) */
    [[nodiscard]] Node root(const Node &x) {
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    /* 木x と 木y を併合し成功したかを返す：𝑶(log n) */
    bool merge(const Node &x, const Node &y) {
        unsigned root_x = root(x);
        unsigned root_y = root(y);
        if (root_x == root_y) return false;
        parent[root_x] = root_y;
        return true;
    }

    /* ノード x, y が属する木は同じか：𝑶(log n) */
    [[nodiscard]] bool same(const Node &x, const Node &y) {
        return root(x) == root(y);
    }
};
