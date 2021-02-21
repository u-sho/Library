#include <bits/stdc++.h>
#define H_MAX 1000
#define W_MAX 1000
#define WALL 'X'

constexpr int INF       = 1e9;
constexpr int MOVE_COST = 1;  // 1回の移動でかかるコスト
// 以下 H_MAX が 3'000 を超える場合は注意
constexpr int WALL_COST = 1e8;  // 1回の壁越えでかかるコスト
int MAX_WALL            = 0;    // 壁越えの最大回数<=8
int MAX_COST            = (MAX_WALL + 1) * WALL_COST - 1;

using std::make_pair;
using std::pair;
using std::queue;
using std::vector;

// grid
using Grid = vector<std::string>;
// gridの左上を(0,0)として(↓,→)の座標
using YX = pair<int, int>;

const vector<YX> MOVES = {
    make_pair(-1, 0),  // 上へ
    make_pair(1, 0),   // 下へ
    make_pair(0, -1),  // 左へ
    make_pair(0, 1)    // 右へ
};

// (H_MAX+2) * (W_MAX+2) のvectorで距離を表す。INFで初期化
// 2に意味はない。0でも良い
vector<vector<int>> d(H_MAX + 2, vector<int>(W_MAX + 2, INF));

using BfsRes = pair<int, queue<YX>>;
/**
 * h: グリッドの高さ
 * w: グリッドの幅
 * m: グリッド
 * starts: 始点リスト
 * goal: 終点
 * c: 始点でのコスト(=0)
 *
 * BfsRes: pair<int, queue<YX>>
 *      (コスト(到達不可能時は-1)，壁リスト)
 */
BfsRes bfs(int h, int w, Grid m, queue<YX> starts, YX goal, int c = 0) {
    // 壁リスト
    queue<YX> next;

    // TODO: ここ定数倍重い
    queue<YX> que;
    while (!starts.empty()) {
        YX s = starts.front();
        starts.pop();

        que.push(s);
        // 始点のコストは c(=0)
        if (d.at(s.first).at(s.second) == INF) {
            d.at(s.first).at(s.second) = c;
        }
    }

    while (!que.empty()) {
        YX prev = que.front();
        que.pop();
        const auto [py, px] = prev;

        // 上下左右を見ていく
        for (const YX &dm : MOVES) {  // dm: 微小なmove
            int y   = py + dm.first;
            int x   = px + dm.second;
            YX curr = make_pair(y, x);

            // 終点なら到達できることを返す
            if (curr == goal) {
                if (d.at(py).at(px) + MOVE_COST <= MAX_COST)
                    return make_pair(d.at(py).at(px) + MOVE_COST, next);
                else
                    return make_pair(-1, next);
            }

            // グリッドの外ならskip
            if (y < 0 || x < 0 || y >= h || x >= w) continue;

            // 壁なら，壁リストに追加してskip
            if (m.at(y).at(x) == WALL) {
                // 壁越えできないならskip
                if (MAX_WALL == 0) continue;

                int wc = d.at(py).at(px) + WALL_COST;

                // 最大コストを越えていたらskip
                if (wc > MAX_COST) continue;

                // 値を INF or x から更新できないならskip
                if (d.at(y).at(x) <= wc) continue;

                // 壁リストに追加する
                d.at(y).at(x) = wc;
                next.push(curr);
                continue;
            }

            // 最短距離を更新できないならskip
            if (d.at(y).at(x) <= d.at(py).at(px) + MOVE_COST) continue;

            // 最短距離を更新してqueに突っ込む
            d.at(y).at(x) = d.at(py).at(px) + MOVE_COST;
            que.push(curr);
        }
    }

    // 壁リストが更新されないなら，到達不能だったってこと
    if (next.empty()) return make_pair(-1, next);

    return bfs(h, w, m, next, goal);
}

// 座標の入力
std::istream &operator>>(std::istream &is, YX &p) {
    is >> p.first >> p.second;
    return is;
}

void abc007_c();  // 最短経路長<----------------------------------Simple
void abc088_d();  // 到達可能か，可能なら最短経路長<--------------いいテスト
void arc005_c();  // 壁をn回越えていいとき，到達可能か
void agc033_a();  // 複数始点から，マップを埋めるのに必要な最小回数
void joi2011yo_e();  // n地点の経由にかかる最短経路長(経路重複あり)(経由の順番は決まっている)
// void agc043_a(); // 通路→壁のときだけコストがかかる

//-----------------------------------------------------------------------main()-----------
int main(void) {
    // agc033_a();
    // arc005_c();
    // abc007_c();
    // abc088_d();
    joi2011yo_e();
    return 0;
}

void agc033_a() {
    int h, w;
    std::cin >> h >> w;

    Grid A(h);
    for (int i = 0; i < h; ++i) std::cin >> A.at(i);

    // 壁から出発する
    queue<YX> blacks;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (A.at(i).at(j) == WALL) blacks.push(make_pair(i, j));
        }
    }

    // d(コスト)をマッピングする
    bfs(h, w, A, blacks, make_pair(h + 2, w + 2), 0);

    // 最大コスト探し
    int ans = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (d.at(i).at(j) != INF) ans = std::max(ans, d.at(i).at(j));
        }
    }

    std::cout << ans << std::endl;
    return;
}

void arc005_c() {
    // ２回壁を越えられる
    MAX_WALL = 2;
    MAX_COST = (MAX_WALL + 1) * WALL_COST - 1;

    int h, w;
    std::cin >> h >> w;

    Grid grid(h);
    for (int i = 0; i < h; ++i) {
        std::cin >> grid.at(i);
    }

    queue<YX> starts;
    YX goal;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (grid.at(i).at(j) == 's') starts.push(make_pair(i, j));
            if (grid.at(i).at(j) == 'g') goal = make_pair(i, j);
        }
    }

    std::cout << ((bfs(h, w, grid, starts, goal).first != -1) ? "YES\n"
                                                              : "NO\n");

    return;
}

void abc007_c() {
    int R, C;
    std::cin >> R >> C;

    YX s, g;
    std::cin >> s;
    std::cin >> g;

    // 0-index
    s.first--;
    s.second--;
    g.first--;
    g.second--;

    queue<YX> starts;
    starts.push(s);

    Grid c(R);
    for (int i = 0; i < R; ++i) {
        std::cin >> c.at(i);
    }

    std::cout << bfs(R, C, c, starts, g).first << std::endl;
    return;
}

void abc088_d() {
    int h, w;
    std::cin >> h >> w;

    Grid s(h);
    for (int i = 0; i < h; ++i) {
        std::cin >> s.at(i);
    }

    queue<YX> starts;
    starts.push(make_pair(0, 0));
    YX goal = make_pair(h - 1, w - 1);

    // 最短経路で通るマス数
    int minDist = bfs(h, w, s, starts, goal, 1).first;

    // 到達不可能なら-1を出力する
    if (minDist < 0) {
        std::cout << minDist << std::endl;
        return;
    }

    // 到達可能なら，はじめの白の個数から最短経路長を引く
    int whites = 0;
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (s.at(i).at(j) != WALL) whites++;
        }
    }
    std::cout << whites - minDist << std::endl;

    return;
}

void joi2011yo_e() {
    const int N_MAX = 9;

    int h, w, n;
    std::cin >> h >> w >> n;

    Grid g(h);
    for (int i = 0; i < h; ++i) {
        std::cin >> g.at(i);
    }

    // viaPlaces = {スタート, 経由地1, 経由地2, ... , ゴール}
    vector<YX> viaPlaces(N_MAX + 1);
    for (int i = 0; i < h; ++i) {
        for (int j = 0; j < w; ++j) {
            if (g.at(i).at(j) == 'S') viaPlaces.at(0) = make_pair(i, j);
            if (g.at(i).at(j) == '1') viaPlaces.at(1) = make_pair(i, j);
            if (g.at(i).at(j) == '2') viaPlaces.at(2) = make_pair(i, j);
            if (g.at(i).at(j) == '3') viaPlaces.at(3) = make_pair(i, j);
            if (g.at(i).at(j) == '4') viaPlaces.at(4) = make_pair(i, j);
            if (g.at(i).at(j) == '5') viaPlaces.at(5) = make_pair(i, j);
            if (g.at(i).at(j) == '6') viaPlaces.at(6) = make_pair(i, j);
            if (g.at(i).at(j) == '7') viaPlaces.at(7) = make_pair(i, j);
            if (g.at(i).at(j) == '8') viaPlaces.at(8) = make_pair(i, j);
            if (g.at(i).at(j) == '9') viaPlaces.at(9) = make_pair(i, j);
        }
    }

    int ans = 0;
    for (int i = 0; i < n; ++i) {
        queue<YX> s;
        s.push(viaPlaces.at(i));

        // viaPlaces[i]->viaPlaces[i+1] のコスト
        ans += bfs(h, w, g, s, viaPlaces.at(i + 1)).first;

        // コストの初期化
        for (int j = 0; j < h; ++j) {
            std::fill(d.at(j).begin(), d.at(j).end(), INF);
        }
    }

    std::cout << ans << std::endl;

    return;
}