#include <stdio.h>
#include <stdlib.h>

#define MAX_VALUES 50

void fillValues(int *);
void printValues(int *);

int compareIntAsc(const void *a, const void *b);
int compareIntDesc(const void *a, const void *b);

void sorter(int (*cmp)(const void *, const void *)) {
    int values[MAX_VALUES];
    int *sorted = values;

    fillValues(sorted);
    qsort(sorted, MAX_VALUES, sizeof(int), cmp);
    printValues(sorted);
}

int main(int argc, char *argv[]) {
    sorter(compareIntAsc);
    sorter(compareIntDesc);

    return 0;
}

void fillValues(int *values) {
    for (int i = 0; i <= MAX_VALUES; i++)
        *values++ = rand();
}

void printValues(int *values) {
    for (int i = 0; i <= MAX_VALUES; i++)
        printf("%d\n", *values++);
}

int compareIntAsc(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if (x > y)
        return 1;
    else if (x < y)
        return -1;
    return 0;
}

int compareIntDesc(const void *a, const void *b) {
    int x = *(int*)a;
    int y = *(int*)b;

    if (x < y)
        return 1;
    else if (x > y)
        return -1;
    return 0;
}
