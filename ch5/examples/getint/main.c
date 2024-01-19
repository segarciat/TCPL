#include <stdio.h>

int getint(int *pn);

int main()
{
    printf("Provide an integer: ");
    int n;
    int status = getint(&n);
    switch(status) {
        case EOF:
            printf("Reached end of input\n");
            break;
        case 0:
            printf("Not a number\n");
            break;
        default:
            printf("Got number\n");
            break;
    }
    printf("n=%d\n", n);
}
