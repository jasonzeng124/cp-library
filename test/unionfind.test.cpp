#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"
#include <assert.h>
#include <time.h>

#include "ds/dsu.hpp"
#include "chinaio.cpp"
intype in;


int main()
{
        int n=in,q=in;

        DSU dsu(n);
        while(q--) {
                int t=in,u=in,v=in;

                if(t) {
                        write(dsu.find(u)==dsu.find(v)),*op++='\n';
                }
                else dsu.unite(u,v);
        }
        return flush(),0;
}
