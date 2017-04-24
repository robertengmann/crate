/*bool.h
  Simple boolean datatype
*/

#define TRUE    1
#define FALSE   0

typedef int bool;


#define DIMENSION  BASED*BASED/* 9*9 board */
#define NCELLS     DIMENSION*DIMENSION  /* 81 cells in a 9*9 problem */

typedef struct {
  int m[DIMENSION+1][DIMENSION+1];/* matrix of board contents */
  int freecount;/* how many open squares remain? */

  point move[NCELLS+1];
} boardtype;

void process_solution(int a[], int k, boardtype *board);
