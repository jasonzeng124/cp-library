#pragma once
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h> // syscalls
#include <immintrin.h>

#include <type_traits>
#include <limits>
using namespace std;

#ifndef INLINE
#define INLINE inline __attribute__((always_inline))
#endif

#include "debug.hpp"

#define IOBUF_SZ (1<<21)

namespace fastio
{
        struct IOPre {
                char num[200];

                constexpr IOPre() : num() {
                        for (int i=0; i<100; i++) {
                                int n=i;
                                for (int d=1; d>=0; d--) {
                                        num[i*2+d] = n%10|'0';
                                        n/=10;
                                }
                        }
                }
        };
        constexpr IOPre iopre;

        char obuf[IOBUF_SZ];
        char* writeptr = obuf;

        INLINE void ioflush() {
                write(1, obuf, writeptr-obuf);
                writeptr=obuf;
        }

        INLINE void write_ensure(int nbytes) {
                assert(nbytes < IOBUF_SZ);
                if (writeptr + nbytes > obuf + IOBUF_SZ) ioflush();
        }

        INLINE void flush_if_debug() {
#ifdef DEBUG
                ioflush();
#endif
        }

        INLINE void print(char x) {
                *writeptr++=x;
                flush_if_debug();
        }

        INLINE void print(const char* x) {
                int len = strlen(x);
                memcpy(writeptr, x, len);
                writeptr+=len;
                flush_if_debug();
        }

        template<typename Int, enable_if_t<is_integral<Int>::value, int> = 69420>
        INLINE void print(Int x) { // doesn't work for INT_MIN but bruh lol
                if (x==0) {
                        print('0');
                        return;
                }
                if constexpr (is_signed<Int>::value)
                        if (x<0) *writeptr++ = '-', x=-x;

                char buf[20]; // log10(2^64) ~= 19.26 digits
                char* p = buf+18;
                while (x >= 10) {
                        memcpy(p, iopre.num + (x%100)*2, 2);
                        x/=100;
                        p-=2;
                }
                if (x!=0)
                        *writeptr++ = x|'0';

                memcpy(writeptr, p+2, buf+18-p);
                writeptr += buf+18-p;
                flush_if_debug();
        }

        template<typename cart, typename... cdrt>
        INLINE void print(cart car, cdrt... cdr) {
                print(car); print(cdr...);
        }

        template<typename Int, enable_if_t<is_integral<Int>::value, int> = 69420>
        INLINE void prints(Int* x, char sep, int len) {
                Int* y = x;
                for (; y+3<x+len; y+=4) {
                        write_ensure(128);
                        print(y[0], sep);
                        print(y[1], sep);
                        print(y[2], sep);
                        if (y+3 == x+len-1) print(y[3]);
                        else print(y[3], sep);
                }
                for (; y<x+len; y++) {
                        write_ensure(32);
                        if (y == x+len-1) print(*y);
                        else print(*y, sep);
                }
        }

        struct IOPost {
                IOPost() {
                        atexit(ioflush);
                }
        } iopost;
}
