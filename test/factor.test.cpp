#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "math/factor.hpp"

int main()
{
        fastio::read_ensure(30);
        int x;fastio::scan(x);

        fastio::write_ensure(30);
        fastio::print(x,':',' ');
        auto y=factor(x);
        fastio::prints(y.data(),' ',y.size());
        fastio::print('\n');
}
