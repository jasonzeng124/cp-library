#include <assert.h>

#include <vector>
#include <functional>
using namespace std;

template<typename T, int LG=20, typename Compare = less<T>>
struct RMQ {
        vector<T> arr;
        vector<T> st[LG];
        int n;
        RMQ(int n) : n(n), arr(n) {
                assert(n <= 1<<LG);
                for(auto& v : st) v.resize(n);
                for(int i=0;i<n;i++) st[0][i]=i;
        }
        T argmin(T a, T b) {
                return less()(a,b) ? a : b;
        }
        void build(vector<int> a) {
                arr = a;
                for(int l=1; l<LG; l++) 
                        for(int i=0; i + (1<<(l-1)) < n; i++)
                                st[l][i] = argmin(st[l-1][i], st[l-1][i + (1<<(l-1))]);
        }
        int query(int l, int r) {
                r++;
                int k = __lg(r-l);
                return argmin(st[k][l], st[k][r-(1<<k)]);
        }
};
