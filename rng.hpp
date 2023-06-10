#include <chrono>
#include <random>
using namespace std;


#ifndef DEBUG
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
#endif
#ifdef DEBUG
mt19937 rng(42);
mt19937_64 rng64(42);
#endif

int randint(int lo, int hi) {
        return uniform_int_distribution<int>(lo,hi)(rng);
}
long long randint64(long long lo, long long hi) {
        return uniform_int_distribution<long long>(lo,hi)(rng64);
}

double randreal(double lo, double hi) {
        return uniform_real_distribution<double>(lo,hi)(rng64);
}
