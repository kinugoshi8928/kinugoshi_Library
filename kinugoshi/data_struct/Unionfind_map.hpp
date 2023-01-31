#pragma once
#ifndef kinugoshi_UF_MAP
#define kinugoshi_UF_MAP
#include <map>
/**
 * @file Unionfind_map.hpp
 * @brief unionfindの頂点をmapで管理できるようにしたやつ
 * $log$がついた代わりに頂点番号の上限がなくなった
 * @note 使うかこれ?
 */

namespace kinugoshi {

template <class UF_MAP>
/**
 * @brief Unionfindの頂点番号上限ない版
 * 頂点追加はmerge(追加したい頂点,追加したい頂点)
 * 初期化:Unionfind_map<頂点番号> UF
 */
struct Unionfind_map {
    /**
     * @brief 親を求める
     * @param x 頂点番号
     * @return UF_MAP xの親
     */
    UF_MAP leader(UF_MAP x) {
        if (par[x] == x) return x;
        else return par[x] = leader(par[x]);
    }
    /**
     * @brief 辺を2つの間につける
     * 頂点の追加もこれで
     */
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
    /**
     * @brief 2つがつながっているかどうか
     * @return true つながっている
     * @return false つながっていない
     */
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