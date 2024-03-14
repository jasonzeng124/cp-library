#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include <assert.h>
#include <time.h>

#include "math/factorial.hpp"
#include "math/dynamic_modint.hpp"
#include "chinaio.cpp"
intype in;

int mod;
typedef dynamic_modint<1> mint;

int main()
{
        int T=in,m=in;
        mint::set_mod(m);
        auto [fact, ifact] = genfact_mod(mint(1), min(m-1, int(1e7)));

        auto choose = [&](int n, int k) -> mint {
                if(k<0||k>n) return 0;
                return fact[n]*ifact[k]*ifact[n-k];
        };
        while(T--) {
                int n=in,k=in;
                write((int)choose(n,k));*op++='\n';
                if(T%100000==0)flush();
        }
        return flush(),0;
}
