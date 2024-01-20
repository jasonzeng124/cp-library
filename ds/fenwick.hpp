#include <vector>

#include <ext/pb_ds/assoc_container.hpp>

#include "hash.hpp"

struct ft_add {
        template<typename T>
        T operator()(T a, T b) const {
                return a + b;
        }
};
struct ft_min {
        template<typename T>
        T operator()(T a, T b) const {
                return min(a, b);
        }
};
struct ft_max {
        template<typename T>
        T operator()(T a, T b) const {
                return max(a, b);
        }
};

template<typename T=long long, typename oper=ft_add>
struct fenwick // oper should be: associative, commutative, has identity
{
        int n; std::vector<T> t; T id;

        fenwick(int n, T id) : n(n), t(n, id), id(id) {}
        fenwick(int n) : fenwick(n, {}) {}
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

template<typename K=int, typename T=long long, typename oper=ft_add, typename H=splitmix<K>>
struct sparse_fenwick // oper should be: associative, commutative, has identity
{
        int n; __gnu_pbds::gp_hash_table<K, T, splitmix<K>> t;

        sparse_fenwick(int n) : n(n) {}
        sparse_fenwick() : sparse_fenwick(0) {}

        void resize(int n) { // UB if tree is nonzero
                this->n=n;
        }

        void update(int i, T x) {
                for(; i<n; i|=i+1) t[i] = oper()(t[i], x);
        }

        T query(int i) {
                T x = {};
                if(i<0) return x;
                for(; ~i; i=(i&(i+1))-1) x = oper()(x, t[i]);
                return x;
        }
};
