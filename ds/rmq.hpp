#include <assert.h>

#include <vector>
#include <functional>
using namespace std;

template<typename T, int LG=20, typename Compare = less<T>>
struct RMQ {
        int n;
        vector<T> arr;
        vector<int> st;
        RMQ(int n) : n(n), arr(n) {
                assert(n <= 1<<LG);
                st.resize(n * LG);
                for(int i=0;i<n;i++) st[i] = i;
        }
        int argmin(int a, int b) {
                return less()(arr[a],arr[b]) ? a : b;
        }
        void build(T* a) {
                for(int i=0;i<n;i++) arr[i] = a[i];
                for(int l=1; l<LG; l++) 
                        for(int i=0; i + (1<<(l-1)) < n; i++)
                                st[l*n+i] = argmin(
                                                st[(l-1)*n + i],
                                                st[(l-1)*n + i + (1<<(l-1))]);
        }
        int query(int l, int r) {
                r++;
                int k = __lg(r - l);
                return argmin(st[k*n + l], st[k*n + r - (1<<k)]);
        }
};
