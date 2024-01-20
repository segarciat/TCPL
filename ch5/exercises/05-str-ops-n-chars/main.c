#include <stdio.h>

void strncat_(char*, char*, int);
void strncpy_(char*, char*, int);
int strncmp_(char*, char*, int);

int main()
{
    printf("strncat test:\n");
    char s[50] = {'h', 'e', '\0'};
    strncat_(s, "llo", 2);
    printf("expected \"%s\", got \"%s\"\n", "hell", s);

    char t[50] = {'h', 'e', '\0'};
    strncat_(t, "llo", 10);
    printf("expected \"%s\", got \"%s\"\n", "hello", t);

    char r[50] = "foo";
    strncpy_(r, "bar", 2);
    printf("expected \"%s\", got \"%s\"\n", "ba", r);
    
    char v[50] = "joey";
    strncpy_(r, "hey", 4);
    printf("expected \"%s\", got \"%s\"\n", "hey", r);

    char w[] = "arduous";
    char u[] = "ardent";
    int cmp = strncmp_(w, u, 3);
    printf("expected \"%d\", got \"%d\"\n", 0, cmp);

    cmp = strncmp_("hello", "world", 3);
    printf("expected negative number, got %d\n", cmp);
}
