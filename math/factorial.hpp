#pragma once
#include <utility>
#include <vector>
#include <functional>
using namespace std;

#include "modint.hpp"

template<typename Int>
pair<vector<Int>,vector<Int>> genfact(Int one, long long n) {
        vector<Int> fact(n+1),ifact(n+1);
        fact[0]=one;
        ifact[0]=one;

        for(int i=1;i<=n;i++) {
                fact[i] = fact[i-1] * (one + i - 1);
                ifact[i] = one / fact[i];
        }
        return {fact,ifact};
}

template<typename InInt, InInt mod>
pair<vector<modular<InInt,mod>>,vector<modular<InInt,mod>>>
genfact_mod(modular<InInt,mod> one, long long n) {
        vector<modular<InInt,mod>> fact(n+1),ifact(n+1);
        fact[0]=one;
        ifact[0]=one;
        fact[1]=one;
        ifact[1]=one;

        for(int i=2;i<=n;i++) {
                auto x = one+i-1;
                fact[i] = fact[i-1] * x;
                ifact[i] = -modular<InInt,mod>(mod/x.x) * ifact[mod%x.x];
        }
        for(int i=1;i<=n;i++) ifact[i] *= ifact[i-1];
        return {fact,ifact};
}
