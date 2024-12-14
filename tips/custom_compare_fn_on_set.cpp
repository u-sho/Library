#include <iostream>
#include <set>
#include <string>

#define BitDP(flag, value) \
    for (decltype(value) flag = 0; flag <= (value); flag += (value))

// custom compare function
struct comp {
    template <class T>
    bool operator()(const T &l, const T &r) const {
        // 点数が同じなら辞書順
        if (l.first == r.first) return l.second > r.second;

        // 基本は点数順
        return l.first < r.first;
    }
};
// こうやって比較関数を渡してあげる
std::set<std::pair<uint, std::string>, comp> participants;

// abc384 c
int main() {
    using namespace std;

    uint a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    BitDP(A, a) BitDP(B, b) BitDP(C, c) BitDP(D, d) BitDP(E, e) {
        const uint score = A + B + C + D + E;
        string solved    = "";
        if (A) solved.push_back('A');
        if (B) solved.push_back('B');
        if (C) solved.push_back('C');
        if (D) solved.push_back('D');
        if (E) solved.push_back('E');

        participants.insert({score, solved});
    }

    const auto first_participant = make_pair(a + b + c + d + e, "ABCDE");

    auto it = participants.lower_bound(first_participant);
    for (uint i = 0; i < 31; ++i) {
        std::cout << it->second << '\n';
        --it;
    }
}
