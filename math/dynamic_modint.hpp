#pragma once
#include <assert.h>

#include <utility>
#include <tuple>
using namespace std;

#include "math/modint.hpp"

template<typename Int, int index>
struct dynamic_modular
{
        Int x; static Int mod;
        dynamic_modular() : x(0) {}

        static int get_mod() { return mod; }
        static void set_mod(Int mod) { dynamic_modular::mod = mod; }

        template<typename T>
        constexpr dynamic_modular(T num) : x(num%mod) { if (x<0) x+=mod; }

        template<typename T>
        constexpr explicit operator T() { return T(x); }

        constexpr dynamic_modular& operator++() {
                x++; if (x==mod) x=0;
                return *this; }
        constexpr dynamic_modular& operator--() {
                if (x==0) x=mod;
                x--; return *this; }
        constexpr dynamic_modular operator++(int) { dynamic_modular res=*this; ++*this; return res; }
        constexpr dynamic_modular operator--(int) { dynamic_modular res=*this; --*this; return res; }

        constexpr bool operator==(const dynamic_modular& y) {
                return x == y.x; }
        constexpr bool operator!=(const dynamic_modular& y) {
                return x != y.x; }
        constexpr dynamic_modular operator+() const { return *this; }
        constexpr dynamic_modular operator-() const { return dynamic_modular()-*this; }

        constexpr dynamic_modular& operator+=(const dynamic_modular& o) {
                x += o.x;
                if (x>=mod) x-=mod;
                return *this; }

        constexpr dynamic_modular& operator-=(const dynamic_modular& o) {
                x -= o.x;
                if (x<0) x+=mod;
                return *this; }

        template<enable_if_t<is_same<Int, int>::value, int> = 69420>
        constexpr dynamic_modular& operator*=(const dynamic_modular& o) {
                x = (long long) x * o.x % mod;
                return *this;
                // https://cs.stackexchange.com/questions/77016/modular-multiplication
                //unsigned long long ab=(long double)x*o.x / mod;
                //long long r = ((long long)x*o.x - ab*mod) % mod;
                //if (r<0) r+=mod;
                //x = r;
                //return *this;
        }
        template<enable_if_t<is_same<Int, long long>::value, int> = 69420>
        constexpr dynamic_modular& operator*=(const dynamic_modular& o) {
                x = (__int128) x * o.x % mod;
                return *this;
        }

        constexpr dynamic_modular& operator/=(const dynamic_modular& o) {
                return *this *= dynamic_modular(o).inv(); }

        constexpr dynamic_modular pow(long long pwr) {
                Int totient = eulerphi(mod);
                if (gcd(x, mod) == 1)
                        pwr = (pwr % totient + totient) % totient;
                assert("modular power must be >= 0" && pwr>=0);
                dynamic_modular power = x;
                dynamic_modular y = 1;
                while (pwr > 0) {
                        if (pwr & 1)
                                y *= power;
                        power *= power;
                        pwr >>= 1;
                }
                return y;
        }

        constexpr dynamic_modular inv() const {
                if (gcd(x, mod) != 1)
                        return 0;

                // by ext. Euclidean algo
                Int bx, bm;
                Int g = extgcd(x, mod, bx, bm); // bx*x + bm*m = g (=1 for primes)
                assert(g==1);
                return bx;
        }
        friend constexpr dynamic_modular operator+(dynamic_modular x, const dynamic_modular& y) { return x+=y; }
        friend constexpr dynamic_modular operator-(dynamic_modular x, const dynamic_modular& y) { return x-=y; }
        friend constexpr dynamic_modular operator*(dynamic_modular x, const dynamic_modular& y) { return x*=y; }
        friend constexpr dynamic_modular operator/(dynamic_modular x, const dynamic_modular& y) { return x/=y; }
};

template<typename Int, int index> Int dynamic_modular<Int, index>::mod;

template<int index> using dynamic_modll = dynamic_modular<long long, index>;
template<int index> using dynamic_modint = dynamic_modular<int, index>;
