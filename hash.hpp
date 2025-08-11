#include <chrono>
#include <functional>

namespace hashing {
using namespace std;

#define _ull unsigned long long

template<typename T>
static _ull splitmix64(T x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        _ull y = hash<T>{}(x);
        y += 0x9e3779b97f4a7c15;
        y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
        y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
        return y ^ (y >> 31);
}

template<typename T>
struct splitmix {
        _ull operator()(_ull x) const {
                static const _ull FIXED_RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
                return splitmix64(x + FIXED_RANDOM);
        }
};

_ull hash_combine(_ull a, _ull b) {
        a ^= b + 0x517cc1b727220a95 + (a << 6) + (a >> 2);
        return a;
}

struct pair_hash {
        template<typename T, typename U>
        _ull operator() (const pair<T,U>& p) const {
                return hash_combine(splitmix<T>{}(p.first), splitmix<T>{}(p.second));
        }
};

struct array_hash {
        template<typename T, unsigned long int N>
        _ull operator() (const array<T,N>& a) const {
                _ull hsh = splitmix<T>{}(a[0]);
                for(unsigned long int i=1; i<N; i++) {
                        hsh = hash_combine(hsh, splitmix<T>{}(a[i]));
                }
                return hsh;
        }
};

}
using namespace hashing;
