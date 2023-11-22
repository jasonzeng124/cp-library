#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "ds/dsu.hpp"

using namespace fastio;

int main()
{
        read_ensure(100);
        int n,q; scan(n,q);

        DSU dsu(n);
        while(q--) {
                int t,u,v; read_ensure(100); scan(t,u,v);

                if(t) {
                        write_ensure(100); print(dsu.find(u)==dsu.find(v),'\n');
                }
                else dsu.unite(u,v);
        }
}
