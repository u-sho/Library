#include <bits/stdc++.h>
constexpr int INF     = 1e9;
constexpr int indexed = 1;  // ノード番号が1始まり

// グラフ：辺の集合で表す
using Graph = std::vector<std::vector<int>>;

/**
 * inputs:
 *      n:ノード数, g:グラフ, s:始点,
 *      (isDist:距離を返すか，最短経路のとき隣接する始点側のノードを返すか)
 *
 * outputs:
 *      vector<int>: 各ノードからstartまでの最短距離(!isDistなら始点側のノード)
 */
std::vector<int> solve(int n, Graph g, int start, bool isDist = true) {
    using std::make_pair;
    using std::pair;
    using std::queue;
    using std::vector;

    // (始点側のノード，startまでの距離)
    // second は到達したかどうかのフラグでも可
    vector<pair<int, int>> dist(n + 1, make_pair(0, INF));
    dist.at(start) = make_pair(start, 0);

    queue<int> que;
    que.push(start);

    // bfs
    while (!que.empty()) {
        int prev = que.front();
        que.pop();

        for (int ge : g.at(prev)) {
            // すでに通っていたらskip
            if (dist.at(ge).second != INF) continue;

            // 直前のノードまでの最短距離+1
            dist.at(ge) = make_pair(prev, dist.at(prev).second + 1);
            // このノードから距離1で到達できるところを探したいのでqueueに突っ込む
            que.push(ge);
        }
    }

    // outputs
    vector<int> res;
    for (int i = indexed; i < n + indexed; ++i) {
        res.push_back(isDist ? dist.at(i).second : dist.at(i).first);
    }
    return res;
}

int main() {
    // n:ノード数，v:辺の数，s:始点，e:終点
    int n, v, s, e;
    std::cin >> n >> v >> s >> e;

    Graph graph(n + indexed);
    for (int i = 0; i < v; ++i) {
        int a, b;
        std::cin >> a >> b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }

    // s->eの最短距離
    std::cout << solve(n, graph, s).at(e) << std::endl;

    return 0;
}
