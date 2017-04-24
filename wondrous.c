#include <stdio.h>
#include <stdlib.h>

int wondrous(int *n);

int main(int argc, char const *argv[]) {
    int n = atoi(argv[1]);
    wondrous(&n);

    return 0;
}

int wondrous(int *n) {
    if (*n == 1) return 1;

    if (*n % 2 == 0) {
        *n = *n / 2;
    } else {
        *n = 3 * *n + 1;
    }

    printf("%d\n", *n);

    return wondrous(n);
}
