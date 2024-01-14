#include <stdio.h> /* printf */
#include <time.h>  /* clock_t clock(void) function; see Appendix B10 */


void populate(int array[], int n);
int binsearch(int x, int v[], int n);
int binsearchv2(int x, int v[], int n);

int main()
{
    int len = 1000000;
    int values[len];
    populate(values, len);

    int searchval = 15781;

    printf("Searching for value %d in array\n", searchval);

    int position;
    clock_t start, end;

    start = clock();
    position = binsearch(searchval, values, len);
    end = clock();

    printf("\n");
    printf("v1 found %d at position %d\n", searchval, position);
    printf("v1 binsearch completed in %f milliseconds\n", (double)(end- start) * 1000 / CLOCKS_PER_SEC);

    start = clock();
    position = binsearch(searchval, values, len);
    end = clock();

    printf("\n");
    printf("v1 found %d at position %d\n", searchval, position);
    printf("v2 binsearch completed in %f milliseconds\n", (double)(end - start) * 1000 / CLOCKS_PER_SEC );
}

void populate(int array[], int len)
{
    int i;
    for(i = 0; i < len; i++)
	 array[i] = i;
}

/* binsearch: find x in v[0] <= v[1] <= ... <= v[n-1] */
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

/* binsearch v2: find x in v[0] <= v[1] <= ... <= v[n-1] */
int binsearchv2(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while(low < high) {
		mid = (low+high) / 2;
		if (x < v[mid])
			high = mid - 1;
		else
			low = mid + 1;
    }
	return (low < n && v[low] == x)? low: -1;
}



