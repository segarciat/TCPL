/* strcmp_: compares at most n characters of s and t */
int strncmp_(char *s, char *t, int n)
{
    for (; *s == *t && n > 0; s++, t++, n--)
	if (*s == '\0')
	    return 0;
    if (n == 0) /* first n characters compared equal */
	return 0;
    return *s - *t;
}
