#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA 512
#define MAX_ROWS INT16_MAX

struct Address {
  int id;
  int set;
  char name[MAX_DATA];
  char email[MAX_DATA];
};

struct Database {
  int top_row;
  struct Address rows[MAX_ROWS];
};

struct Connection {
  FILE *file;
  struct Database *db;
};
