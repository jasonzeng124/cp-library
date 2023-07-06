#pragma once
#include "opt.hpp"
#include <string.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h> // syscalls
#include <immintrin.h>

#include <limits>
#include <type_traits>
using namespace std;

#include "debug.hpp"

// TODO: fastio debug mode
#define IOBUF_SZ (1<<21)

namespace fastio
{
#ifdef DEBUG
        bool isfirst = true;
#endif
        char ibuf[IOBUF_SZ*2+1];
        char* readptr = ibuf;
        char* rendptr = ibuf;

        INLINE void ioload() { // 2-buf swapping
#ifdef DEBUG
                if(isfirst && isatty(fileno(stdin)))
                        dprintf(REDTEXT "Running from a terminal! Use Ctrl-D to give EOF.\nAlso, in interactive problems, #define PRELOAD 0\n" RESETEXT);
                isfirst=false;
#endif
                assert(readptr <= rendptr);
                if (rendptr < ibuf+IOBUF_SZ) {
                        memcpy(ibuf+IOBUF_SZ, readptr, rendptr-readptr);
                        int off = rendptr - readptr;
                        readptr = ibuf+IOBUF_SZ;
                        rendptr = readptr + off;
                        rendptr += read(0, rendptr, IOBUF_SZ-off);
                }
                else {
                        memcpy(ibuf, readptr, rendptr-readptr);
                        int off = rendptr - readptr;
                        readptr = ibuf;
                        rendptr = readptr + off;
                        rendptr += read(0, rendptr, IOBUF_SZ-off);
                }
                *rendptr = 0;
        }
        struct IOPreIn {
                IOPreIn() {
#ifndef PRELOAD
#define PRELOAD 1
#endif
#if PRELOAD
                        ioload();
#endif
                }
        } iopre_in;

        INLINE void read_ensure(int nbytes) {
                assert(nbytes < IOBUF_SZ);
                if (readptr + nbytes > rendptr) ioload();
        }

        INLINE void skip_white() {
                while (*readptr <= ' ' && readptr < rendptr) {
                        readptr++;
                }
        }

        INLINE void scan(char& x) {
                x=*readptr++;
        }

        template<typename Int, enable_if_t<is_integral<Int>::value, int> = 69420>
        INLINE void scan(Int& x) {
                skip_white();
                char c = *readptr++;

                [[maybe_unused]] bool minus=false;
                if constexpr (is_signed<Int>::value)
                        if (c=='-') minus=true, c=*readptr++;

                x=0;
                while (c>='0') {
                        x = x*10 + (c&15);
                        c = *readptr++;
                }
                if constexpr (is_signed<Int>::value)
                        if (minus) x=-x;
        }

        template<typename cart, typename... cdrt>
        INLINE void scan(cart& car, cdrt&... cdr) {
                scan(car); scan(cdr...);
        }

        INLINE void scans(char* x, int len) {
                for (; len>=20; len-=20) {
                        read_ensure(20);
                        memcpy(x, readptr, 20);
                        readptr+=20;
                        x += 20;
                }
                read_ensure(20);
                memcpy(x, readptr, len);
                readptr += len;
        }

        template<typename Int, enable_if_t<is_integral<Int>::value, int> = 69420>
        INLINE void scans(Int* x, int len) {
                Int* y = x;
                for (; y+3<x+len; y+=4) {
                        read_ensure(200);
                        scan(y[0]);
                        scan(y[1]);
                        scan(y[2]);
                        scan(y[3]);
                }
                for (; y<x+len; y++) {
                        read_ensure(60);
                        scan(*y);
                }
        }
}
