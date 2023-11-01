#include <assert.h>
#include <stdint.h>
#include <array>
#include <vector>

#include "opt.hpp"


namespace _factor_detail {
        using namespace std;
        typedef uint32_t ui;

        __attribute__((cold))
        void factor_helper(vector<ui>& v, ui& x, ui y) {
                do {
                        v.push_back(y);
                        x /= y;
                } while(x % y == 0);
        }

        const int maxp = 31623, P = 3401;

        constexpr auto primes = []() constexpr {
                int ptr = 0;
                array<ui, P> primes{};
                array<bool, maxp> comp{};
                for(int p = 2; p < maxp; p++) {
                        if(!comp[p]) {
                                primes[ptr++]=p;
                                for(int j = p; j < maxp; j += p)
                                        comp[j] = 1;
                        }
                }
                assert(ptr==P);
                return primes;
        }();

        template<int L=0, int R=P-1, int M=(L+R)/2>
        constexpr void factor_(vector<ui>& v, ui& x) {
                if constexpr (L < R) {
                        factor_<L,M>(v,x);
                        if(L + 40 < R && x < primes[M]*primes[M]) return;
                        factor_<M+1,R>(v,x);
                }
                else if (x % primes[L] == 0) factor_helper(v, x, primes[L]);
        }
}

std::vector<int> factor(uint32_t x) {
        assert(x<=1e9);
        std::vector<uint32_t> v;
        using namespace _factor_detail;
#pragma GCC unroll(19)
        for(int i=0;i<19;i++) {
                if(x<primes[179*i]*primes[179*i]) break;
#pragma GCC unroll(179)
                for(int j=179*i;j<179*(i+1);j++)
                        if(x%primes[j]==0)[[unlikely]]
                                factor_helper(v,x,primes[j]);
        }
        //_factor_detail::factor_(v, x);
        if(x > 1) v.push_back(x);
        return std::vector<int>{v.begin(),v.end()};
}
