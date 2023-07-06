#include <chrono>
#include <functional>
using namespace std;

template<typename T>
static unsigned long long splitmix64(T x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        unsigned long long y = hash<T>{}(x);
        y += 0x9e3779b97f4a7c15;
        y = (y ^ (y >> 30)) * 0xbf58476d1ce4e5b9;
        y = (y ^ (y >> 27)) * 0x94d049bb133111eb;
        return y ^ (y >> 31);
}

template<typename T>
struct splitmix {

        unsigned long long operator()(unsigned long long x) const {
                static const unsigned long long FIXED_RANDOM = chrono::high_resolution_clock::now().time_since_epoch().count();
                return splitmix64(x + FIXED_RANDOM);
        }
};

unsigned long long hash_combine(unsigned long long a, unsigned long long b) {
        a ^= b + 0x517cc1b727220a95 + (a << 6) + (a >> 2);
        return a;
}

template<typename T, typename U>
struct pair_hash {
        unsigned long long operator() (const pair<T,U>& p) const {
                return splitmix<T>{}(p.first) * 69 + splitmix<U>{}(p.second);
        }
};
