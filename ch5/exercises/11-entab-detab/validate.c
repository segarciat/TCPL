#include <stdio.h>
#include <stdlib.h> /* strtol */

/* validate: returns 1 if there are no command-line arguments, or it contains a monotonically increasing list
 * of natural nubmers
 *
 * argc and argv is the number of arguments, and the arguments, passed to main
 * */
int validate(int argc, char *argv[])
{
    if (argc == 1) {
        printf("using default tab: \n");
    } else {
        int i, prevtabstop = 0, base = 10;
        char *endp;
        for (i = 1; i < argc; i++) {
            long val = strtol(argv[i], &endp, base);
            if (*endp == '\0' && val > prevtabstop) {
                prevtabstop = val;
            } else {
                printf("invalid number: %s\n", endp);
                return 0;
            }
        }
    }
    return 1;
}
