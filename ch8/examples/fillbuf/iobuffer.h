#ifndef _H_IOBUFF
#define _H_IOBUFF
#include "stdio_excerpt.h"
FILE _iob[OPEN_MAX] = {		/* stdin, stdout, stderr: */
    { 0, (char *) 0, (char *) 0, _READ, 0 },
    { 0, (char *) 0, (char *) 0, _WRITE, 1 },
    { 0, (char *) 0, (char *) 0, _WRITE | _UNBUF, 2 }
};
#endif
