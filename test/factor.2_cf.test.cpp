#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "math/factor.hpp"

int main()
{
        fastio::read_ensure(30);
        int tt;fastio::scan(tt);
        while(tt--) {
                fastio::read_ensure(30);
                int x;fastio::scan(x);

                fastio::write_ensure(30);
                auto y=factor(x);
                fastio::print(y.size(),'\n');
                //fastio::prints(y.data(),' ',y.size());
                //fastio::print('\n');
        }
}
