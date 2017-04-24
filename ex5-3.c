#include <stdio.h>

void strcatz(char *a, char *b) {
    for (int i = 0; *a+i != '\0'; i++) {
        b+i = *a+i;
    }
}

int main(int argc, char *argv[]) {
    char *foo = "Foo";
    char *bar = "Bar";
    strcatz(foo, bar);

    printf("%s\n", foo);
    return 0;
}
