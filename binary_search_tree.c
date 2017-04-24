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

  while(t->left != NULL) {
    min = min->left;
  }

  return min;
}

tree *find_maximum(tree *t) {
  if(t == NULL) return NULL;

  tree *max;
  max = t;

  while(t->right != NULL) {
    max = max->right;
  }

  return max;
}

void insert_tree(tree **l, int x, tree *parent) {
  tree *p;

  if(*l == NULL) {
    p = malloc(sizeof(tree));
    p->item = x;
    p->left = p->right = NULL;
    p->parent = parent;
    *l = p;
    return;
  }

  if(x < (*l)->item) {
    insert_tree(&((*l)->left), x, *l);
  } else {
    insert_tree(&((*l)->right), x, *l);
  }
}

int main(int argc, char *argv[]) {

  tree **t = NULL;
  insert_tree(t, 1, NULL);
  insert_tree(t, 8, NULL);
  insert_tree(t, 9, NULL);

  return 0;
}
