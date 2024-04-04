#pragma once
#include <assert.h>

#include <utility>
#include <tuple>

using namespace std;

template<typename Int>
constexpr Int gcd(Int a, Int b)
{
        if (a==0 or b==0) return a+b;
        int az = __builtin_ctz(a);
        int bz = __builtin_ctz(b);
        int shift = min(az, bz);
        b>>=bz;

        while (a != 0) {
                a>>=az;
                Int d = b>a?b-a:a-b;
                az = d==0?0:__builtin_ctz(d);
                b = min(a, b);
                a = d;
        }
        return b<<shift;
}

template<typename Int>
constexpr Int extgcd(Int a0, Int b0, Int& x, Int& y)
{
        Int xa = 1, ya = 0;
        Int xb = 0, yb = 1;
        Int a = a0, b = b0;
        while (b != 0) {
                Int q = a / b;
                tie(xa, xb) = make_pair(xb, xa - q * xb);
                tie(ya, yb) = make_pair(yb, ya - q * yb);
                tie(a, b) = make_pair(b, a - q * b);
        }
        x = xa; y = ya;
        return a;
}

template<typename Int>
constexpr Int eulerphi(Int x)
{
        Int phi = x;
        for (int p = 2; 1ll * p * p < x; p++) { // eulerphi = x * PI over x's prime factors: 1-1/p
                if (x % p == 0) {
                        x /= p;
                        phi = phi / p * (p - 1);
                        while (x % p == 0)
                                x /= p;
                }
        }
        if (x != 1) phi = phi / x * (x - 1);
        return phi;
}

template<typename Int>
constexpr bool isprime(Int x) {
        return eulerphi(x)==x-1;
}

template<typename Int, Int mod>
struct modular
{
        typedef Int intty;
        Int x;
        modular() : x(0) {}

        static int get_mod() { return mod; }

        template<typename T>
        constexpr modular(T num) : x(num%mod) { if (x<0) x+=mod; }

        template<typename T>
        constexpr explicit operator T() { return T(x); }

        constexpr modular& operator++() {
                x++; if (x==mod) x=0;
                return *this; }
        constexpr modular& operator--() {
                if (x==0) x=mod;
                x--; return *this; }
        constexpr modular operator++(int) { modular res=*this; ++*this; return res; }
        constexpr modular operator--(int) { modular res=*this; --*this; return res; }

        constexpr bool operator==(const modular& y) {
                return x == y.x; }
        constexpr bool operator!=(const modular& y) {
                return x != y.x; }
        constexpr modular operator+() const { return *this; }
        constexpr modular operator-() const { return modular()-*this; }

        constexpr modular& operator+=(const modular& o) {
                x += o.x;
                if (x>=mod) x-=mod;
                return *this; }

        constexpr modular& operator-=(const modular& o) {
                x -= o.x;
                if (x<0) x+=mod;
                return *this; }

        template<typename U = Int, typename std::enable_if<std::is_same<U, int>::value, int>::type = 0>
        constexpr modular& operator*=(const modular& o) {
                x = (long long) x * o.x % mod;
                return *this;
        }
        template<typename U = Int, typename std::enable_if<std::is_same<U, long long>::value, int>::type = 0>
        constexpr modular& operator*=(const modular& o) {
                 https://cs.stackexchange.com/questions/77016/modular-multiplication
                unsigned long long ab=(long double)x*o.x / mod;
                long long r = ((long long)x*o.x - ab*mod) % mod;
                if (r<0) r+=mod;
                x = r;
                return *this;
                //x = (__int128) x * o.x % mod;
                //return *this;
        }
        constexpr modular& operator/=(const modular& o) {
                return *this *= modular(o).inv(); }

        constexpr modular pow(long long pwr) {
                Int totient = eulerphi(mod);
                if (gcd(x, mod) == 1)
                        pwr = (pwr % totient + totient) % totient;
                assert("modular power must be >= 0" && pwr>=0);
                modular power = x;
                modular y = 1;
                while (pwr > 0) {
                        if (pwr & 1)
                                y *= power;
                        power *= power;
                        pwr >>= 1;
                }
                return y;
        }

        constexpr modular inv() const {
                if (gcd(x, mod) != 1)
                        return 0;

                // by ext. Euclidean algo
                Int bx, bm;
                Int g = extgcd(x, mod, bx, bm); // bx*x + bm*m = g (=1 for primes)
                assert(g==1);
                return bx;
        }
        friend constexpr modular operator+(modular x, const modular& y) { return x+=y; }
        friend constexpr modular operator-(modular x, const modular& y) { return x-=y; }
        friend constexpr modular operator*(modular x, const modular& y) { return x*=y; }
        friend constexpr modular operator/(modular x, const modular& y) { return x/=y; }
};

template<long long mod> using modll = modular<long long, mod>;
template<int mod> using modint = modular<int, mod>;
