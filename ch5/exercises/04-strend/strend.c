/* strend: returns 1 if string t occurs at the end of s, and 0 otherwise
 *
 * e.g.: strend("operand", "and") => 1
 * e.g.: strend("ate", "debate") => 0
 * */
int strend(char *s, char *t)
{
    char *start_t = t;

    while(*s && *t) {
	s++;
	t++;
    }
    if (*s == '\0' && *t != '\0') /* t is longer than s */
	return 0;

    while(*s)	/* reach end of s */
	s++;
    while(*t) 	/* reach end of t */
	t++;

    while(*--s == *--t && start_t != t)		/* compare */
	;
    return start_t == t;
}
