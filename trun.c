#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char *name;
    int age;
} Person;

Person create_person(char *name, int age) {
  Person *person;
  person->name = name;
  person->age = age;
  return *person;
}

void print_person(Person *person) {
  printf("Person: %s (%d)\n", *person->name, *person->age);
}

int main(int argc, char *argv[]) {
  print_person(create_person(argv[0], atoi(argv[1])));
  return 0;
}
