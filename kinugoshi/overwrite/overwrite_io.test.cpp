#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include "kinugoshi/overwrite/overwrite_io.hpp"

#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    vector<pair<long long, long long>> A(T);
    cin >> A;
    for (int i = 0; i < T; i++) cout << A[i].first + A[i].second << endl;
}