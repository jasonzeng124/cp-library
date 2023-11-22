#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "ds/lca.hpp"

using namespace fastio;

int main()
{
        read_ensure(100);
        int n,q; scan(n,q);

        vector<vector<int>> ch(n);
        for(int i=1;i<n;i++) {
                int p; read_ensure(100); scan(p);
                ch[p].push_back(i);
        }

        LCA lca(n); lca.build(ch);

        while(q--) {
                int u,v; read_ensure(100); scan(u,v);

                write_ensure(100); print(lca.lca(u,v), '\n');
        }
}
