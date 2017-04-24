#include <stdio.h>
#include <stdlib.h>


#define MAXN 100

long fib_rec(long n);
long fib_dyn(long n);


int main(int argc, char const *argv[]) {

    long long result = 0;
    char m = argv[1][0];
    long n = atol(argv[2]);

    if (n > MAXN) {
        printf("Input too large (max. %d).", MAXN);
        return -1;
    }

    if (m == 'r') {
        result = fib_rec(n);
    } else if (m == 'd') {
        result = fib_dyn(n);
    } else {
        printf("Choose correct mode.");
        return -1;
    }

    printf("%lld\n", result);

    return 0;
}

long fib_dyn(long n) {
    long long f[MAXN+1];
    f[0] = 0;
    f[1] = 1;

    for (int i = 2; i <= n; i++) {
        f[i] = f[i-1] + f[i-2];
    }

    return f[n];
}

long fib_rec(long n) {
    if (n == 0 || n == 1) {
        return n;
    }

    return fib_rec(n-1) + fib_rec(n-2);
}
