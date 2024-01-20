/* strcat: copy t to the end of s. Assumes s has enough room for all characters in s and t */
void strcat_(char *s, char *t)
{
    while (*s) /* find end of s */
	s++;
    while(*s++ = *t++) /* copy t to s */
	;
}
