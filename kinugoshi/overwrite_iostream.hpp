#include <iostream>
#include <utility>
#include <vector>
namespace std {
// pair
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &v) {
    os << v.first << " " << v.second;
    return os;
}
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &v) {
    is >> v.first >> v.second;
    return is;
}
// vector
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i != (int)v.size() - 1 ? " " : "");
    }
    return os;
}
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}
}  // namespace std