#include <stdio.h>

int getfloat(double *pn);

int main()
{
    printf("Provide an integer: ");
    double n;
    int status = getfloat(&n);
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
    printf("n=%f\n", n);
}
