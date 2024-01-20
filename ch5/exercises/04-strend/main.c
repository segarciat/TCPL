#include <stdio.h>

int strend(char*, char*);
void test(char*, char*);

int main()
{
    test("operand", "and");
    test("ate", "debate");
    test("chocolate", "vanilla");
}

void test(char *s, char *t)
{
    printf("\"%s\" and \"%s\": %d\n", s, t, strend(s, t));
}
