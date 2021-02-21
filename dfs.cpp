#include <iostream>
#include <vector>
constexpr std::size_t N_MAX = 200'005UL;  //'

// 辺の集合
using Graph = std::vector<std::vector<int>>;

std::vector<bool> visited(N_MAX);

void dfs(const Graph &g, const int &s = 1) {
    visited.at(s) = true;
    // ここに処理をかく

    for (const int &next : g.at(s)) {
        if (visited.at(next)) continue;
        dfs(g, next);
    }
    return;
};

// abc138_d