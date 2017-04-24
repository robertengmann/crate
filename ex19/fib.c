#include <stdio.h>
#include <stdlib.h>


long fib_r(int n) {
  if (n == 0) return 0;
  if (n == 1) return 1;

  return fib_r(n-1) + fib_r(n-2);
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  long fib = fib_r(n);

  printf("Result: %li\n", fib);

  return 0;
}
