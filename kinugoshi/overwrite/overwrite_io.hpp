#include <iostream>
#include <utility>
#include <vector>
/**
 * @file overwrite_stl.hpp
 * @brief STLのオーバーライド寄せ集め
 * 今のところcin/coutのオーバーライドのみ
 * @details cin/coutをpair/vectorに対応させる
 * @note 早解き用なので、デバッグ用ではない
 * デバッグにはgdb+VSCodeを使おう
 */
namespace std {
/**
 * @brief pair型のostreamオーバーライド
 * @tparam T v.firstの型
 * @tparam U v.secondの型
 * @param[in] os ostreamをもってきただけ
 * @param[in] v 出力するpair
 * {1,4}ならば"1 4￥n"となる
 * @return ostream& お作法
 */
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &v) {
    os << v.first << " " << v.second;
    return os;
}
/**
 * @brief pair型のistreamオーバーライド
 * @tparam T v.firstの型
 * @tparam U v.secondの型
 * @param[in] is istreamをもってきただけ
 * @param[out] v 入力されるpair型
 * "1 4/n"と入力されているならば {1,4}となる
 * @return istream& お作法
 */
template <typename T, typename U>
istream &operator>>(istream &is, pair<T, U> &v) {
    is >> v.first >> v.second;
    return is;
}
/**
 * @brief vector型のostreamオーバーライド
 * @tparam T vectorの型
 * @param[in] os ostreamをもってきただけ
 * @param v 出力するvector
 * {1,4,4,5}ならば"1 4 4 5￥n"となる
 * @return ostream& お作法
 */
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v) {
    for (int i = 0; i < (int)v.size(); i++) {
        os << v[i] << (i != (int)v.size() - 1 ? " " : "\n");
    }
    return os;
}
/**
 * @brief vector型のistreamオーバーライド
 * @tparam T vectorの型
 * @param[in] is istreamをもってきただけ
 * @param[out] v 入力されるvector
 * 要素数だけ入力されるので初期化を忘れないように
 * @return istream& お作法
 */
template <typename T>
istream &operator>>(istream &is, vector<T> &v) {
    for (T &in : v) is >> in;
    return is;
}
}  // namespace std