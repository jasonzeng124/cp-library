#include <vector>

#include <ext/pb_ds/assoc_container.hpp>

#include "hash.hpp"
#include "func.hpp"

template<typename T=long long, typename oper=func_add, T id={}>
struct fenwick // oper should be: associative, commutative, has identity
{
        int n; std::vector<T> t;

        fenwick(int n) : n(n), t(n, id) {}
        fenwick() : fenwick(0) {}

        void resize(int n) { // UB if tree is nonzero
                this->n=n;
                t.resize(n);
        }

        void update(int i, T x) {
                for(; i<n; i|=i+1) t[i] = oper()(t[i], x);
        }

        T query(int i) {
                T x = id;
                if(i<0) return x;
                for(; ~i; i=(i&(i+1))-1) x = oper()(x, t[i]);
                return x;
        }
};

template<typename K=int, typename T=long long, typename oper=func_add, T id={}, typename H=splitmix<K>>
struct sparse_fenwick // oper should be: associative, commutative, has identity
{
        int n; __gnu_pbds::gp_hash_table<K, T, splitmix<K>> t;

        sparse_fenwick(int n) : n(n) {}
        sparse_fenwick() : sparse_fenwick(0) {}

        T get(K i) {
                auto it = t.find(i);
                if(it == t.end()) return t[i] = id;
                return *it;
        }

        void resize(int n) { // UB if tree is nonzero
                this->n=n;
        }

        void update(int i, T x) {
                for(; i<n; i|=i+1) t[i] = oper()(get(i), x);
        }

        T query(int i) {
                T x = {};
                if(i<0) return x;
                for(; ~i; i=(i&(i+1))-1) x = oper()(x, get(i));
                return x;
        }
};
