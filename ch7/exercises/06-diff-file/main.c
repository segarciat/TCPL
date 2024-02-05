#include <stdio.h>	/* fprintf, stderr */
#include <stdlib.h>	/* exit */
#include <string.h>	/* strcmp */

#define NFILES 2
#define MAXLEN 1000

void compare(FILE *, FILE*);

int main(int argc, char *argv[])
{
    char* prog = argv[0];
    if (--argc != NFILES) {
	fprintf(stderr, "Usage: %s <FILE1> <FILE2>\n", prog);
	exit(1);
    }

    /* Open files to be compared */
    char *filename1, *filename2;
    FILE *fp1, *fp2;
    if ((fp1 = fopen(filename1 = *++argv, "r")) == NULL) {
	fprintf(stderr, "%s: can't open %s\n", prog, *argv);
	exit(1);
    }
    if ((fp2 = fopen(filename2 = *++argv, "r")) == NULL) {
	fprintf(stderr, "%s: can't open %s\n", prog, *argv);
	exit(1);
    }

    /* read text until difference is found */
    char f1line[MAXLEN], f2line[MAXLEN], *s1, *s2;
    do {
	s1 = fgets(f1line, MAXLEN, fp1);
	s2 = fgets(f2line, MAXLEN, fp2);
    } while (s1 != NULL && s2 != NULL && strcmp(f1line, f2line) == 0);
    fclose(fp1);
    fclose(fp2);
    /* display whatever is different */
    if (s1 != NULL || s1 != NULL)
        printf("%s:\n%s\n%s:\n%s\n", filename1, (s1 == NULL) ? "": s1, filename2, (s2 == NULL)? "": s2);
    if (ferror(stdout)) {
	fprintf(stderr, "%s: error writing stdout\n", prog);
	exit(1);
    }
    exit(0);
}
