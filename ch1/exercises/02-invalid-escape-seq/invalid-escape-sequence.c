#include <stdio.h>

main()
{
    /* \z is an invalid escape sequence */
    printf("Hello, world\z\n");
}
