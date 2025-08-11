#pragma once
#include <utility>
#include <vector>
#include <functional>
using namespace std;

#include "modint.hpp"

template<typename Int>
pair<vector<Int>,vector<Int>> genfact(int n) {
        vector<Int> fact(n+1),ifact(n+1);
        fact[0]=Int(1);

        for(int i=1;i<=n;i++) {
                fact[i] = fact[i-1] * i;
        }
        ifact[n] = fact[0] / fact[n];
        for(int i=n-1;~i;i--) {
                ifact[i] = ifact[i+1] * (i+1);
        }
        return {fact,ifact};
}
