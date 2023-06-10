#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,tune=native")
#pragma clang attribute push (__attribute__((target("avx2,bmi,bmi2,lzcnt,popcnt"))),apply_to=function)

#include <time.h>

#include "io/fastio.hpp"
using namespace fastio;

#define ll long long

int main()
{
        clock_t start = clock();
        read_ensure(32);
        int n; scan(n);

        for (int i=0; i<n; i++) {
                read_ensure(40);
                ll a, b; scan(a, b);
                write_ensure(32);
                print(a+b, '\n');
        }
        fprintf(stderr, "time: %lf\n", float(clock()-start)/CLOCKS_PER_SEC);
}
#pragma clang attribute pop
