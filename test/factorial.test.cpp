#define PROBLEM "https://judge.yosupo.jp/problem/binomial_coefficient_prime_mod"
#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "math/factorial.hpp"
#include "math/dynamic_modint.hpp"

int mod;
typedef dynamic_modint<1> mint;

int main()
{
        fastio::read_ensure(500);
        fastio::write_ensure(500);
        int T, m; fastio::scan(T, m);
        mint::set_mod(m);
        auto [fact, ifact] = genfact_mod(mint(1), min(m-1, int(1e7)));

        auto choose = [&](int n, int k) -> mint {
                if(k<0||k>n) return 0;
                return fact[n]*ifact[k]*ifact[n-k];
        };
        while(T--) {
                fastio::read_ensure(50);
                int n, k; fastio::scan(n,k);
                fastio::write_ensure(50);
                fastio::print((int)choose(n, k),'\n');
        }
}
