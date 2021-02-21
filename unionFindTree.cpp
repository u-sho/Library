#include <vector>
class UnionFind {
    std::vector<int> parent;
    UnionFind(int n) : parent(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int root(int x) {  // データx が属する木の根
        if (parent[x] == x) return x;
        return parent[x] = root(parent[x]);
    }

    void merge(int x, int y) {  // 木x と 木y を併合
        int root_x = root(x);
        int root_y = root(y);
        if (root_x == root_y) return;
        parent[root_x] = root_y;
    }

    bool same(int x, int y) {  // データx, y が属する木は同じか
        return root(x) == root(y);
    }
};
