#include <string.h> /* strcmp */
#include <ctype.h>

/* qsort: sort v[left]...v[right] into increasing order */
void qsort(char *v[], int left, int right, int reversed, int fold, int (*comp)(void *, void *, int))
{
    int i, last;
    void swap(void *v[], int i, int j);
    void stolower(char *);

    if (left >= right)  /* do nothing if array contains fewert than two elements */
        return;
    swap(v, left, (left + right)/2);
    last = left;
    for (i = left+1; i <= right; i++) {
        if ((*comp)(v[i], v[left], fold) * reversed < 0)
            swap(v, ++last, i);
    }
    swap(v, left, last);
    qsort(v, left, last-1, reversed, fold, comp);
    qsort(v, last+1, right, reversed, fold, comp);
}

/* swap: interchange v[i] and v[j] */
void swap(void *v[], int i, int j)
{
    void *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}
