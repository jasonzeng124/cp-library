#define PROBLEM "https://judge.yosupo.jp/problem/lca"
#include <assert.h>
#include <time.h>

#include "ds/lca.hpp"
#include "chinaio.cpp"
intype in;

int main()
{
        int n=in,q=in;

        vector<vector<int>> ch(n);
        for(int i=1;i<n;i++) {
                int p=in;
                ch[p].push_back(i);
        }

        LCA lca(n); lca.build(ch);

        while(q--) {
                int u=in,v=in;
                write(lca.lca(u,v));*op++='\n';
        }
        return flush(),0;
}
