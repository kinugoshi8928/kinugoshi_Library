#line 1 "Unionfind_map.test.cpp"
#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#line 2 "Unionfind_map.hpp"
#ifndef kinugoshi_UF_MAP
#define kinugoshi_UF_MAP
#include <map>

namespace kinugoshi {

template <class UF_MAP>
struct Unionfind_map {
    // map版UF
    // 初期化 Unionfind_map<string> tree; など
    UF_MAP leader(UF_MAP x) {
        if (par[x] == x) return x;
        else return par[x] = leader(par[x]);
    }
    void merge(UF_MAP x, UF_MAP y) {
        if (par.find(x) == par.end()) par[x] = x;
        if (par.find(y) == par.end()) par[y] = y;
        UF_MAP lx = leader(x), ly = leader(y);
        if (lx == ly) return;
        if (rank[lx] < rank[ly]) par[lx] = ly;
        else {
            par[ly] = lx;
            if (rank[lx] == rank[ly]) rank[lx]++;
        }
    }
    bool same(UF_MAP x, UF_MAP y) {
        if (par.find(x) == par.end()) par[x] = x;
        if (par.find(y) == par.end()) par[y] = y;
        return leader(x) == leader(y);
    }

   private:
    std::map<UF_MAP, int> par, rank;
};
}  // namespace kinugoshi
#endif  // kinugoshi_UF_MAP
#line 3 "Unionfind_map.test.cpp"
#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using namespace kinugoshi;
using ll = long long;
using mint = modint998244353;
#define all(v) v.begin(), v.end()
#define rep(a, b) for (long long a = 0; a < (long long)(b); a++)
int op(int a, int b) { return min(a, b); }
int e() { return 2147483647; }

int main() {
    int N, Q;
    cin >> N >> Q;
    Unionfind_map<int> UF;
    rep(i, Q) {
        int t, u, v;
        cin >> t >> u >> v;
        if (t == 0) UF.merge(u, v);
        else cout << UF.same(u, v) << endl;
    }
}
