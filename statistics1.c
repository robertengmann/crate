#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

double mean(int *arr, int N);
double median(int *arr, int N);
int mode(int *arr, int N);
int compare_ints(const void* a, const void* b);


int main(int argc, char const *argv[]) {
    int N;
    scanf("%d", &N);

    int arr[N];
    for (int arr_i = 0; arr_i < N; arr_i++)
       scanf("%d", &arr[arr_i]);

    printf("%2.1f\n", mean(arr, N));
    printf("%2.1f\n", median(arr, N));
    printf("%d\n", mode(arr, N));

    return 0;
}

double mean(int *arr, int N) {
    double result = 0;

    for(int i = 0; i < N; i++)
        result += arr[i];

    return result / N;
}

int compare_ints(const void* a, const void* b)
{
    int arg1 = *(const int*)a;
    int arg2 = *(const int*)b;

    return (arg1 > arg2) - (arg1 < arg2);
}

double median(int *arr, int N) {
    int half = N / 2;
    qsort(arr, N, sizeof(int), compare_ints);

    return (arr[half-1] + arr[half]) / 2.0;
}

int mode(int *arr, int N) {
    qsort(arr, N, sizeof(int), compare_ints);

    return arr[0];
}
