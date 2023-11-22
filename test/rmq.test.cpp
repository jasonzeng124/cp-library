#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"
#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "ds/rmq.hpp"

#include <vector>
using namespace std;

using namespace fastio;

int main()
{
        read_ensure(100);
        int n,q; scan(n,q);

        vector<int> a(n);
        scans(a.data(),n);

        RMQ<int> rmq(n);
        rmq.build(a.data());
        while(q--) {
                int u,v; read_ensure(100); scan(u,v);

                write_ensure(100); print(a[rmq.query(u,--v)],'\n');
        }
}
