#ifndef UTILS_DEFS_HPP
#define UTILS_DEFS_HPP

#ifndef NULL
#define NULL (void*)0
#endif

#ifndef STUB
#include <cstdio>
#define STUB                                     \
    printf("%s#L%i STUB\n", __FILE__, __LINE__); \
    return
#endif

#endif