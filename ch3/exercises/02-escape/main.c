#include <stdio.h>
#define MAXLEN 1000

void escape(const char s[], char t[]);
void unescape(const char[], char t[]);

int main()
{
    char escaped[MAXLEN];
    char unescaped[MAXLEN] = "\nto whom it may concern\n\n\thave a nice day\n\nsincerely, computer\n";
    escape(unescaped, escaped);
    printf("escaped:\n%s\n", escaped);
    unescape(escaped, unescaped);
    printf("unescaped:\n%s\n", unescaped);
}

/* escape: copies s into t, replacing invisible characters such as newlines and tabs to
 * visible escape sequences like \n, \t. Assumes t has enough room */
void escape(const char s[], char t[])
{
    int i, j;
    j = 0;
    for (i = 0; s[i] != '\0'; i++) {
	switch(s[i]) {
	    case '\n':
		t[j++] = '\\';
		t[j++] = 'n';
		break;
	    case '\t':
		t[j++] = '\\';
		t[j++] = 't';
		break;
	    default:
	        t[j++] = s[i];
		break;
	}
    }
    t[j++] = '\0';
}

/* unescape: takes a escaped string s and copies it into t while displaying escape sequences 
 * Note: does not handle hex or octal (\xhh, \ooo)
 * */
void unescape(const char s[], char t[])
{
    int i, j;

    int hasslash = 0;
    j = 0;
    for (i = 0; s[i] != '\0'; i++) {
	if (s[i] == '\\') {
	    hasslash = 1;
	} else if (hasslash) {
	    switch(s[i]) {
		case 'a':
		    t[j++] = '\a';
		    break;
		case 'b':
		    t[j++] = '\b';
		    break;
		case 'f':
		    t[j++] = '\f';
		    break;
		case 'n':
		    t[j++] = '\n';
		    break;
		case 'r':
		    t[j++] = '\r';
		    break;
		case 't':
		    t[j++] = '\t';
		    break;
		case 'v':
		    t[j++] = '\v';
		    break;
		case '\\':
		    t[j++] = '\\';
		    break;
		case '?':
		    t[j++] = '\?';
		    break;
		case '\'':
		    t[j++] = '\'';
		    break;
		case '\"':
		    t[j++] = '\"';
		    break;
		default:
		    break;
	    }
	    hasslash = 0;
	} else {
	    t[j++] = s[i];
	}
    }
    t[j++] = '\0';
}
