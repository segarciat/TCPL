#include <stdio.h> /* NULL, printf */
#include "nlist.h"

struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *name);
void undef(char *name);

int main()
{
    install("pi", "3.14");
    install("e", "2.718");
    install("i^2", "-1");
    undef("e");
    struct nlist *list = lookup("e");	/* should be NULL */
    if (list != NULL)
	printf("expected NULL, but instead got entry: (%s, %s)\n", list->name, list->defn);
    else
	printf("success! undef removed the entry\n");
}
