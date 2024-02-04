#ifndef HNODES
#define HNODES
struct wtree {
    char* word;			/* word found in text */
    int frequency;		/* frequency of appearance of word */
    struct wtree *left;		/* left tree child node */
    struct wtree *right;	/* right tree child node */
};
struct wordlist {
    char* word;
    struct wordlist *next;
};
struct ftree {			/* word-frequency-ordered tree */
    int frequency;		/* frequency of all words in the list stored in this tree node */
    struct wordlist *first;	/* list of words of equal frequency */
    struct ftree *left;		/* subtree of smaller frequency words */
    struct ftree *right;	/* subtree of larger frequency words */
};
#endif
