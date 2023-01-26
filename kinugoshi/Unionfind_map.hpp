#pragma once
#ifndef kinugoshi_UF_MAP
#define kinugoshi_UF_MAP
#include <map>

namespace kinugoshi {

template <class UF_MAP>
struct Unionfind_map {
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