#define PROBLEM "https://judge.yosupo.jp/problem/many_aplusb"

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt,tune=native")
#pragma clang attribute push (__attribute__((target("avx2,bmi,bmi2,lzcnt,popcnt"))),apply_to=function)

#include <time.h>

#include "chinaio.cpp"

#define ll long long

int main()
{
        clock_t start = clock();
        int n=read();

        for (int i=0; i<n; i++) {
                ll a=read(),b=read();
                write(a+b); *op++='\n';
                if(i&~0xff)flush();
        }
        fprintf(stderr, "time: %lf\n", float(clock()-start)/CLOCKS_PER_SEC);

        return flush(),0;
}
#pragma clang attribute pop
