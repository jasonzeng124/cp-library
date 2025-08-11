#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <assert.h>
#include <time.h>

#include "ds/isegtree.hpp"
#include "chinaio.cpp"
intype in;

using namespace std;

int main()
{
        int n=in,q=in;

        vector<long long> a(n);
        for(auto&x:a)x=in;

        isegtree<long long> st(n);
        st.build(a);
        while(q--) {
                int t=in,u=in,v=in;

                if(t) {
                        write(st.query(u,v-1));*op++='\n';
                }
                else st.update(u,a[u]+=v);
        }
        return flush(),0;
}
