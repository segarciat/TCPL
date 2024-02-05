#include <stdio.h>	/* printf, fprintf, FILE, fopen, NULL, stderr, stdin, fgets */
#include <string.h>	/* strstr */
#include <stdlib.h>	/* exit */

#define MAXLINE 1000


void findmatches(FILE *fp, char *pattern, char line[],  int except, int number);

/* find: print lines from standard input (or named files) that match pattern from 1st arg  */
int main(int argc, char *argv[])
{
    char line[MAXLINE], *prog, *pattern;
    int c, except = 0, number = 0;
    FILE *fp;

    prog = argv[0];
    for (--argc, ++argv; argc > 1 && (*argv)[0] == '-'; argc--, argv++)
   /* while(--argc > 0 && (*++argv)[0] == '-') */ /* advance command-line argument array pointer */
	while(c = *++argv[0]) /* advance pointer of first command-line argument */
	    switch (c) {
		case 'x':
		    except = 1;
		    break;
		case 'n':
		    number = 1;
		    break;
		default:
		    fprintf(stderr, "%s: illegal option %c\n", prog, c);
		    exit(1);
		    break;
	    }

    if (argc < 1) {
	fprintf(stderr, "Usage: %s -x -n pattern [FILE]...\n", prog);
	exit(1);
    }
    pattern = *argv;
    if (argc == 1) {
	findmatches(stdin, pattern, line, except, number);
    } else {
	int manyfiles = --argc > 1;
	while (argc-- > 0)
	    if ((fp = fopen(*++argv, "r")) == NULL) {
		fprintf(stderr, "%s: can't open %s\n", prog, *argv);
		exit(1);
	    } else {
		if (manyfiles)
		    printf("%s:\n", *argv);
		findmatches(fp, pattern, line, except, number);
		fclose(fp);
	    }
    }
    if (ferror(stdout)) {
	fprintf(stderr, "%s: error writing stdout\n", prog);
	exit(2);
    }
    exit(0);
}

void findmatches(FILE *fp, char *pattern, char line[],  int except, int number)
{
    int found = 0;
    long lineno = 0;
    while (fgets(line, MAXLINE, fp) != NULL) {
	lineno++;
	if ((strstr(line, pattern) != NULL) != except) {
	    if (number)
		printf("%ld: ", lineno);
	    printf("%s", line);
	    found++;
	}
    }
    printf("%d\n", found);
}
