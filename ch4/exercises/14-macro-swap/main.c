#include <stdio.h>
#define	swap(t, x, y)	{t temp = x; x = y, y = temp;}

int main()
{
    int s = 5;
    int t = -10;
    printf("before swap s=%d, t=%d\n", s, t);

    swap(int, s, t);

    printf("after swap s=%d, t=%d\n", s, t);
}
