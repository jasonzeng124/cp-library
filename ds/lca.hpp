#include <assert.h>

#include <vector>
#include "ds/rmq.hpp"
using namespace std;

template<int LG=20>
struct LCA {
        RMQ<int> rmq;
        vector<int> ord, dep, ti;
        int t=0;

        LCA(int n) : rmq(2*n), ord(2*n), dep(2*n), ti(n) {
                assert(2*n <= 1<<LG);
        }

        void dfs(vector<vector<int>>& ch, int v, int d) {
                ti[v]=t;
                dep[t]=d;
                ord[t++]=v;
                for(auto x : ch[v]) {
                        dfs(ch, x, d + 1);
                        dep[t]=d;
                        ord[t++]=v;
                }
        }

        void build(vector<vector<int>>& ch, int rt=0) {
                dfs(ch, rt, 0);
                rmq.build(dep.data());
        }

        int lca(int u, int v) {
                if(ti[u] > ti[v]) swap(u, v);
                int x = rmq.query(ti[u], ti[v]);
                return ord[x];
        }
};
