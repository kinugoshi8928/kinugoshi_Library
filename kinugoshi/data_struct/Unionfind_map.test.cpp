#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include "kinugoshi/data_struct/Unionfind_map"

#include <bits/stdc++.h>
using namespace std;
using namespace kinugoshi;
using ll = long long;
#define all(v) v.begin(), v.end()
#define rep(a, b) for (long long a = 0; a < (long long)(b); a++)

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