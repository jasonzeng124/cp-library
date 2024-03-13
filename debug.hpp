#pragma once
#include <stdio.h>

#define REDTEXT   "\033[1;31m"
//#define GREENTEXT "\033[1;32m"
#define GREENTEXT "\033[38;5;34m"
#define BLUETEXT  "\033[1;34m"
#define RESETEXT  "\033[0m"

#ifdef DEBUG
#ifndef dprintf
#define dprintf(args...) fprintf(stderr, args)
#endif
#define display(args...) dprintf(#args), dprintf("\n")
#endif

#ifndef DEBUG
#ifndef dprintf
#define dprintf(...)
#endif
#define display(...)
#endif
