/* strncat: copy at most n characters of t to the end of s. Assumes s has enough room in s */
void strncat_(char *s, char *t, int n)
{
    while (*s) /* find end of s */
	s++;
    while(n > 0 && (*s++ = *t++)) /* copy t to s */
	n--;
}
