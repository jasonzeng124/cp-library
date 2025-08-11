#include <vector>

#include "func.hpp"

template<typename T=long long, typename oper=func_add, T id={}>
struct isegtree // oper should be: associative, has identity
{
        int n; std::vector<T> t;

        isegtree(int n) : n(n), t(2*n-1, id) {}
        isegtree() : isegtree(1) {}

        void resize(int n) { // UB if tree is nonzero
                this->n=n;
                t.resize(2*n-1);
        }

        template<typename Tp>
        void build(Tp a) {
                for(int i=n-1;~i;i--) t[i+n-1] = a[i];
                for(int i=n-2;~i;i--) t[i] = oper()(t[i*2+1], t[i*2+2]);
        }

        void update(int i, T x) {
                i += n-1;
                t[i] = x;
                while(i > 0) i = (i-1)/2, t[i] = oper()(t[i*2+1], t[i*2+2]);
        }

        T query(int l, int r) {
                l += n-1; r += n-1;
                T lans = id, rans = id;
                while(l < r) {
                        if(~l&1) lans = oper()(lans, t[l++]);
                        if(r&1)  rans = oper()(t[r--], rans);
                        l = (l-1) / 2;
                        r = (r-1) / 2;
                }
                if(l == r) return oper()(oper()(lans, t[l]), rans);
                else return oper()(lans, rans);
        }
};
