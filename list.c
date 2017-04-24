#include <stdlib.h>
#include <stdio.h>


typedef struct int_list {
  int item;
  struct int_list *next;
} int_list;

void add_to_int_list(int_list **list, int item) {
  int_list *p;
  p = malloc(sizeof(int_list));
  p->item = item;
  p->next = *list;
  *list = p;
}

void print_list(int_list *list) {
  if(list) {
    printf("%d\n", list->item);
    if(list->next) {
      return print_list(list->next);
    }
  }
}

int main(int argc, char *argv[]) {
  int_list **list = malloc(sizeof(int_list));

  for(int i = 1; i <= argc-1; i++) {
    add_to_int_list(list, atoi(argv[i]));
  }

  print_list(*list);

  free(list);
  return 0;
}
