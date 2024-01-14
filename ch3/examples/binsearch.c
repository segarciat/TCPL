#include <stdio.h>

int binsearch(int x, int v[], int n);

int main()
{
    int values[] = {-17, -4, 3, 5, 11};
    int len = 5;
    int searchval = -4;
    
    int i;
    for (i = 0; i < len; i++) {
	printf("%d ", values[i]);
    }
    printf("\n");

    printf("value %d is found at position %d\n", searchval, binsearch(searchval, values, len));
}


/* find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low <= high) {
	mid = (low+high) / 2;
	if (x < v[mid])
	    high = mid - 1;
	else if (x > v[mid])
	    low = mid + 1;
	else
	    return mid;
    }
    return -1;
}
