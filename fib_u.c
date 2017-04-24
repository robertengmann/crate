#include <stdio.h>
#include <stdlib.h>

long fib_ultimate(int n) {
  long back2 = 0, back1 = 1;
  long next;

  if(n == 0) return 0;

  for(int i = 2; i < n; i++) {
    next = back1 + back2;
    back2 = back1;
    back1 = next;
  }

  return back1 + back2;
}

int main(int argc, char *argv[]) {
  int n = atoi(argv[1]);
  long fib = fib_ultimate(n);

  printf("%li\n", fib);
  return 0;
}
