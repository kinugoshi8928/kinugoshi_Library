#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "kinugoshi/Unionfind_map.hpp"
#include <bits/stdc++.h>
using namespace std;
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