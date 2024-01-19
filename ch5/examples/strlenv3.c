/* strlen: return length of string s 
 *
 * Notes: According to the book, the number of characters in the string
 * could be too large to store in an int. The header <stddef.h> defines
 * a type ptrdiff_t that is large enough to hold the signed difference
 * of two pointer values. However, it also suggests being even more cautious,
 * and using instead size_t, to match the standard library version.
 *
 * size_t is the unsigned integer type returned by the sizeof operator.
 * */
int strlen(char *s)
{
    char *p = s;

    while(*p != '\0')
	p++;
    return p - s;
}
