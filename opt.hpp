#pragma once
#ifdef OFAST
#pragma GCC optimize("Ofast,unroll-loops")
#endif
#ifndef OFAST
#pragma GCC optimize("O3")
#endif

#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
