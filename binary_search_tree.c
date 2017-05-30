#include <stdlib.h>
#include <stdio.h>


typedef struct tree {
  int item;
  struct tree *parent;
  struct tree *left;
  struct tree *right;
} tree;

tree *search_tree(tree *t, int x) {
  if(t == NULL) return NULL;

  if(t->item == x) return t;

  if(x < t->item) {
    return search_tree(t->left, x);
  } else {
    return search_tree(t->right, x);
  }
}

tree *find_minimum(tree *t) {
  if(t == NULL) return NULL;

  tree *min;
  min = t;

  while(min->left != NULL) {
    min = min->left;
  }

  return min;
}

tree *find_maximum(tree *t) {
  if(t == NULL) return NULL;

  tree *max;
  max = t;

  while(max->right != NULL) {
    max = max->right;
  }

  return max;
}

tree *insert_tree(tree *l, int x, tree *parent) {
  tree *p;

  if(l == NULL) {
    p = malloc(sizeof(tree));
    p->item = x;
    p->left = p->right = NULL;
    p->parent = parent;
    l = p;
    return l;
  }

  if(x < l->item) {
    l->left = insert_tree(l->left, x, l);
  } else {
    l->right = insert_tree(l->right, x, l);
  }

  return l;
}

void print_tree(tree *t) {
  if(t == NULL) return;

  printf("%i\n", t->item);
  print_tree(t->left);
  print_tree(t->right);
}

int main(int argc, char *argv[]) {

  tree *t = NULL;

  for(int i = 1; i <= 12; i++) {
    t = insert_tree(t, i, NULL);
  }
  
  printf("Tree:\n");
  print_tree(t);

  tree *min = find_minimum(t);
  tree *max = find_maximum(t);

  printf("Min: %i\n", min->item);
  printf("Max: %i\n", max->item);

  return 0;
}
