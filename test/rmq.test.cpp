#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <assert.h>
#include <time.h>

#include "ds/rmq.hpp"
#include "chinaio.cpp"
intype in;

#include <vector>
using namespace std;

int main()
{
        int n=in,q=in;

        vector<int> a(n);
        for(auto&x:a)x=in;

        RMQ<int> rmq(n);
        rmq.build(a.data());
        while(q--) {
                int u=in,v=in;
                write(a[rmq.query(u,--v)]);*op++='\n';
        }
        return flush(),0;
}
