#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"
#include <bits/stdc++.h>
#include "kinugoshi/overwrite_iostream.hpp"
using namespace std;
int main() {
    int T;
    cin >> T;
    vector<pair<long long, long long>> A(T);
    cin >> A;
    for (int i = 0; i < T; i++) cout << A[i].first+A[i].second << endl;
}