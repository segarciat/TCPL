#include <stdio.h>

void qsort(int[], int, int);
void show(int[], int);

int main()
{
    int v[] = {-2, 7, 0, 43, 1};
    int len = 5;
    printf("before qsort\n");
    show(v, len);

    qsort(v, 0, len-1);

    printf("after qsort\n");
    show(v, len);
}

void show(int v[], int len)
{
    int i;
    for (i = 0; i < len; i++)
	printf("%d ", v[i]);
    printf("\n");
}

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(int v[], int left, int right)
{
    int i, last;
    void swap(int v[], int i, int j);

    if (left >= right)	/* do nothing if array contains */
	return;		/* fewert than two elements */
    swap(v, left, (left + right) / 2);	/* move partition element */
    last = left;			/* to v[0] */
    for (i = left+1; i <= right; i++)	/* partition */
	if (v[i] < v[left])
	    swap(v, ++last, i);
    swap(v, left, last);		/* restore partition element */
    qsort(v, left, last-1);
    qsort(v, last+1, right);
}

/* swap: exchange elements at position j and i of array v */
void swap(int v[], int i, int j)
{
    int temp;
    
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
