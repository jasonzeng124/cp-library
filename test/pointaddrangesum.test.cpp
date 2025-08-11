#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"
#include <assert.h>
#include <time.h>

#include "ds/fenwick.hpp"
#include "chinaio.cpp"
intype in;

using namespace std;

int main()
{
        int n=in,q=in;

        vector<int> a(n);
        for(auto&x:a)x=in;

        fenwick<long long> ft(n);
        for(int i=0;i<n;i++) ft.update(i, a[i]);
        while(q--) {
                int t=in,u=in,v=in;

                if(t) {
                        write(ft.query(v-1)-ft.query(u-1));*op++='\n';
                }
                else ft.update(u,v);
        }
        return flush(),0;
}
