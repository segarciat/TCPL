#include <stdio.h> 	/* EOF, printf */
#include <string.h>	/* strcmp */
#include <ctype.h>	/* isalpha */
#include "nodeops.h"

#define MAXLEN 100

int getword(char*, int);
void printftree(struct ftree *ftroot);

/* reads in a document and display every word, along with the line numbers where it was found */
int main(int argc, char* argv[])
{
    char word[MAXLEN];
    struct wtree *wtroot;	/* tree of all words */
    wtroot = NULL;
    while (getword(word, MAXLEN) != EOF)
	if (isalpha(word[0]))
	    wtroot = addwtnode(wtroot, word);
    struct ftree *ftroot = NULL;
    ftroot = make_ftree(ftroot, wtroot);
    printftree(ftroot);
}

/* printwlist: displays list of words with a given frequency */
void printwlist(int frequency, struct wordlist *node)
{
    if (node == NULL)
	return;
    else if (node->next != NULL)
	printwlist(frequency, node->next);
    printf("%d %s\n", frequency, node->word);
}

/* printftree: prints all words in free long with their frequency in descending frequency order */
void printftree(struct ftree *ftnode)
{
    if (ftnode != NULL) {
	printftree(ftnode->right);
	printwlist(ftnode->frequency, ftnode->first);
	printftree(ftnode->left);
    }
}
