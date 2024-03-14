#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include <assert.h>
#include <time.h>

#include "math/factor.hpp"
#include "chinaio.cpp"
intype in;

int main()
{
        int x=in;

        write(x);*op++=':';*op++=' ';
        auto y=factor(x);
        for(int i=0;i<y.size();i++)
                (i?*op++=' ':' '),write(y[i]);
        *op++='\n';
        return flush(),0;
}
