#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "ds/fenwick.hpp"

using namespace fastio;

int main()
{
        read_ensure(100);
        int n,q; scan(n,q);

        vector<int> a(n);
        scans(a.data(),n);

        fenwick<long long> ft(n);
        while(q--) {
                int t,u,v; read_ensure(100); scan(t,u,v);

                if(t) {
                        write_ensure(100); print(ft.query(v)-ft.query(u-1),'\n');
                }
                else ft.update(u,v);
        }
}
