#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <assert.h>
#include <time.h>

#include "ds/fenwick.hpp"
#include "chinaio.cpp"
intype in;

int main()
{
        int n=in,q=in;

        vector<int> a(n);
        for(auto&x:a)x=in;

        fenwick<long long> ft(n);
        while(q--) {
                int t=in,u=in,v=in;

                if(t) {
                        write(ft.query(v)-ft.query(u-1));*op++='\n';
                }
                else ft.update(u,v);
        }
        return flush(),0;
}
