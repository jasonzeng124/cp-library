#include <assert.h>

#include <vector>
using namespace std;

template<typename edge_t>
struct adj_vector
{
        int vertices = -1;
        vector<pair<int, edge_t>> acc_edge;
        vector<edge_t> adj;
        vector<int> start;

        adj_vector(int v) : vertices(v) {};
        adj_vector(int v, int e) : vertices(v) {
                acc_edge.reserve(e);
        }

        void add(int a, edge_t edge) {
                acc_edge.emplace_back(a, edge);
        }

        void prepare() {
                assert(vertices != -1);
                adj.resize(acc_edge.size());
                vector<int> nind(vertices+1);
                for (auto [v, e] : acc_edge) {
                        nind[v+1]++;
                }
                for (int i=1; i<=vertices; i++) {
                        nind[i] += nind[i-1];
                }
                start = nind;
                for (auto [v, e] : acc_edge) {
                        adj[nind[v]++] = e;
                }
                vector<pair<int,edge_t>>().swap(acc_edge);
        }

        void clear() {
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
