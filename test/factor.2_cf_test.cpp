#include <assert.h>
#include <time.h>

#include "math/factor.hpp"
#include "chinaio.cpp"
intype in;

int main()
{
        int tt=in;
        while(tt--) {
                int x=in;

                auto y=factor(x);
                write(y.size());*op++='\n';
        }
        return flush(),0;
}
