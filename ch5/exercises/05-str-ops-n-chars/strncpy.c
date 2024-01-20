/* strncpy_: copy at most n charaters of t to s, padding s with 0s if t has less than t characters */
void strncpy_(char *s, char *t, int n)
{
    while (n > 0 && (*s++ = *t++))
	n--;
    do {
	*s++ = '\0';
    } while (--n > 0);
}
