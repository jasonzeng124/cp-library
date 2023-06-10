#define PROBLEM "https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_1_A"
#include <assert.h>
#include <time.h>

#include "io/fastio.hpp"
#include "math/modint.hpp"
typedef modint<7> mint7;
typedef modint<1'000'000'007> mint;

int main()
{
        mint7 x = 3;

        assert(x==3);
        assert(x!=4);
        assert(x==10);

        x = 9;

        assert(x==2);
        assert(++x==3);
        assert(x++==3);
        assert(x==4);
        x--;x--;
        assert(x==2);
        x += 11;
        assert(x==6);
        assert(x+9==1);
        assert(x==6);

        long long y, z;
        int g = extgcd(66, 674, y, z);
        assert(y==143 && z==-14 && g==2);
        assert(eulerphi(12)==4);
        assert(eulerphi(667)==616);

#define cm ,
        assert((x.pow(2))==1);
        assert(mint7(4).pow(2)==2);
        assert(modint<667>(33).pow(999)==618);

        assert(mint7(3).pow(-1)==5);
        assert(modint<667>(33).inv()==283);
        assert(modint<667>(33).inv(1)==283);

        assert(mint(12345).inv()==203483193);
        assert(modint<1'000'000'007>(12345).inv(1)==203483193);

        assert(modint<1'000'000'000>(12345).inv(1)==0);

        unsigned long long rng=0x6969696969420;
        int mod = 1000'000'007;
        clock_t start = clock();
        while (float(clock()-start)/CLOCKS_PER_SEC < 2) {
                rng ^= rng << 13;
                rng ^= rng >> 7;
                rng ^= rng << 17;
                long long ra=rng;
                rng ^= rng << 13;
                rng ^= rng >> 7;
                rng ^= rng << 17;
                long long rb=rng;
                mint xa=ra,xb=rb;
                ra=(ra%mod+mod)%mod;
                rb=(rb%mod+mod)%mod;
                assert(xa==ra); assert(xb==rb);

                assert(xa+xb==(ra+rb)%mod);
                assert(xa*xb==(ra*rb)%mod);
                assert(xa*xa.inv(0)==1);
                assert(xa*xa.inv(1)==1);
                assert(xa.pow(5)==ra*ra%mod*ra%mod*ra%mod*ra%mod);

                xa++,ra=(ra+1)%mod;xb--,rb=(rb-1+mod)%mod;
                assert(xa+xb==(ra+rb)%mod);
                assert(xa*xb==(ra*rb)%mod);
                assert(xa*xa.inv(0)==1);
                assert(xa*xa.inv(1)==1);

                xa+=12093,ra=(ra+12093)%mod;
                assert(xa+xb==(ra+rb)%mod);
                assert(xa*xb==(ra*rb)%mod);
                assert(xa*xa.inv(0)==1);
                assert(xa*xa.inv(1)==1);
                long long int asdf, basdf;
                assert(gcd(ra, rb) == extgcd(ra, rb, asdf, basdf));
        }

        fastio::write_ensure(20);
        fastio::print("Hello World\n");
}
