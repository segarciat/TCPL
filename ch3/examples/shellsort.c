#include <stdio.h>

void show(int values[], int n);
void shellsort(int v[], int n);

int main()
{
    int values[] = {7, -2, 15, -6, 0};
    int len = 5;

    printf("values: ");
    show(values, len);

    shellsort(values, len);

    printf("sorted: ");
    show(values, len);
}

void show(int values[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", values[i]);
    printf("\n");
}

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;

    for (gap = n / 2; gap > 0; gap /= 2)
	for (i = gap; i < n; i++)
	    for(j = i - gap; j>=0 && v[j] > v[j+gap]; j-=gap) {
		/* swap */
		temp = v[j];
		v[j] = v[j+gap];
		v[j+gap] = temp;
	    }
}
