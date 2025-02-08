#include <assert.h>

#include <vector>
using namespace std;

template<typename edge_t>
struct adj_vector
{
        int nvert = -1;
        vector<pair<int, edge_t>> acc_edge;
        vector<edge_t> adj;
        vector<int> start;

        adj_vector(int v) : nvert(v) {};
        adj_vector(int v, int e) : nvert(v) {
                acc_edge.reserve(e);
                adj.reserve(e);
        }

        void add(int a, edge_t edge) {
                acc_edge.emplace_back(a, edge);
        }

        void prepare() {
                assert(nvert != -1);
                adj.resize(acc_edge.size());
                vector<int> nind(nvert+1);
                for (auto [v, e] : acc_edge) {
                        nind[v+1]++;
                }
                for (int i=1; i<=nvert; i++) {
                        nind[i] += nind[i-1];
                }
                start = nind;
                for (auto [v, e] : acc_edge) {
                        adj[nind[v]++] = e;
                }
                acc_edge.clear();
        }

        void shrink() {
                vector<pair<int,edge_t>>().swap(acc_edge);
        }

        void clear() {
                acc_edge.clear();
                adj.clear();
                start.clear();
        }

        void clear_mem() {
                vector<pair<int, edge_t>>().swap(acc_edge);
                vector<edge_t>().swap(adj);
                vector<int>().swap(start);
        }

        inline int deg(int v) {
                return start[v+1] - start[v];
        }

        struct edge_range {
                __gnu_cxx::__normal_iterator<edge_t*, vector<edge_t>> first, last;
                auto begin() { return first; }
                auto end() { return last; }
        };

        inline edge_range operator[] (int v) {
                return {adj.begin()+start[v], adj.begin()+start[v+1]};
        }
};
