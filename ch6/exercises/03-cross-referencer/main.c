#include <stdio.h> 	/* EOF, printf */
#include <string.h>	/* strcmp */
#include <ctype.h>	/* isalpha */
#include "nodeops.h"

#define MAXLEN 100
extern char **NOISE_WORDS;
#define COUNT_NOISE_WORDS (sizeof NOISE_WORDS / sizeof NOISE_WORDS[0])

int binsearch(char*, char*[], int);;
int getword(char*, int);
void printwords(struct tnode*);

/* reads in a document and display every word, along with the line numbers where it was found */
int main(int argc, char* argv[])
{
    char word[MAXLEN];
    struct tnode *root;		/* tree of all words */
    root = NULL;
    int line = 1;
    while (getword(word, MAXLEN) != EOF) {
	if (isalpha(word[0])) {
	    if (binsearch(word, NOISE_WORDS, COUNT_NOISE_WORDS >= 0))
		root = addtnode(root, word, line);
	}
        else if (word[0] == '\n'){
	    line++;
	}
    }
    printwords(root);
}

/* binsearch: returns the index of word w in the words array, or -1 if not found */
int binsearch(char *w, char *words[], int len)
{
    int low, high, mid, cond;
    low = 0;
    high = len - 1;
    while (low < high) {
        mid = low + (high - low) / 2;
	if ((cond = strcmp(w, words[mid])) < 0)
	    high = mid -1;
	else if (cond > 0)
	    low = mid + 1;
	else
	    return mid;
    }
    return -1;
}

/* printlines: print line numbers starting at oldest node */
void printlines(struct xrefnode* node)
{
    if (node == NULL)
	return;
    else if (node->next != NULL)
	printlines(node->next);
    printf(" %d", node->line);
}

/* printwords: print word and line numbers seen */
void printwords(struct tnode* node)
{
    if (node != NULL) {
	printwords(node->left);
	printf("%s:", node->word);
	printlines(node->linenode);
	printf("\n");
	printwords(node->right);
    }
}
