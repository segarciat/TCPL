#include <stdio.h> 	/* NULL, printf */
#include <string.h>	/* strcmp */
#include <ctype.h>	/* isalpha */
#include "nlist.h"

#define MAXLEN 100

struct nlist *install(char *name, char *defn);
struct nlist *lookup(char *name);
void undef(char *name);

int getch(void);
void ungetch(int);
int getword(char *, int);

void handle_comments(int);
void handle_char_literal(int);
void handle_string_literal(int);
void handle_define_command(int, char *, char *);

int main()
{
    int c, d;
    char word[MAXLEN], def[MAXLEN];
    while ((c = getch()) != EOF) {
	if (c == '/') {	/* possible start of a comment */
	    handle_comments(c);
	} else if (c == '\'') { /* entered char; read all of it */
	    handle_char_literal(c);
	} else if (c == '"') {	/* entered string; read all of it */
	    handle_string_literal(c);
	} else if (c == '#') {	/* encountered processor/preprocessor */
	    if (getword(word, MAXLEN) != EOF) {
		if (strcmp(word, "define") == 0) {
		    handle_define_command(c, word, def);
		} else {
		    putchar(c);	/* # symbol read */
		    printf("%s", word);
		}
	    } else
		putchar(c);
	} else if (isalpha(c)) {
	    ungetch(c);
	    getword(word, MAXLEN);
	    struct nlist *keyval = lookup(word);
	    printf("%s", (keyval == NULL) ? word: keyval->defn);
	} else {
	    putchar(c);
	}
    }
    printf("\n");
}

void handle_comments(int c)
{
    int d;
    d = getch();
    if (d != '*') {	/* not a commment */
	putchar(c);
	ungetch(d);
    } else {	/* entered a comment: read all of it, without outputting anything */
	c = getch();
	do {
	    d = c;
	    c = getch();
	} while(c != '/' || d != '*');
    }
}

void handle_char_literal(int c)
{
    int d;
    do {
	d = c;
	c = getch();
	putchar(d);
    } while (c != '\'' || d == '\\');
    putchar(c);
}

void handle_string_literal(int c)
{
    int d;
    do {
	d = c;
	c = getch();
	putchar(d);
    } while (c != '"' || d == '\\');
    putchar(c);
}

void handle_define_command(int c, char* word, char* def)
{
    char *p;

    getword(word, MAXLEN);	/* read in key provided to define */

    while (isspace(c = getch()))	/* skip white space */
	;
    p = def;		/* read in value until newline or comment is reached */
    do {
	*p++ = c;
	c = getch();
    } while (c != '\n' && (*(p-1) != '/' || c != '*'));
    if (c == '\n')
	putchar(c);
    else {
	ungetch(c);
	ungetch(*--p);	/* backtrack since p-1 was '/' */
    }
    *p = '\0';
    install(word, def);
}
