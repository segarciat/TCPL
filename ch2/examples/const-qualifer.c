#include <stdio.h>

int main()
{
    /* const qualifier makes an array read-only */
    const char greeting[] = "hello";
    greeting[1] = 'a';
    printf("%s\n", greeting);
}
