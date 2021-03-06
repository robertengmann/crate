#include <stdio.h>
#include <string.h>
#include "bool.h"

#define	BASEDIMENSION	3
#define DIMENSION	BASEDIMENSION*BASEDIMENSION
#define NCELLS		DIMENSION*DIMENSION
#define MAXCANDIDATES   100		/* max possible next extensions */
#define NMAX            100		/* maximum solution size */

typedef char* data;			/* type to pass data to backtrack */

int board[DIMENSION+1][DIMENSION+1];
int freecount;				/* how many cells are open? */

bool possible[DIMENSION+1];		/* what is possible for the square */

int lastx[NCELLS+1], lasty[NCELLS+1];	/* positions of last move */

extern bool finished;			/* solution found, stop search */

/**********************************************************************/

void possible_values(int x, int y, bool possible[])
{
        int i,j;			/* counters */
	int xlow,ylow;			/* origin of box with (x,y) */
	bool init;			/* is anything/everthing possible? */

	if (board[x][y] != 0)
		init = FALSE;
	else
		init = TRUE;

        for (i=1; i<=DIMENSION; i++) possible[i] = init;

	for (i=0; i<DIMENSION; i++)
		if (board[x][i] != 0) possible[ board[x][i] ] = FALSE;

	for (i=0; i<DIMENSION; i++)
		if (board[i][y] != 0) possible[ board[i][y] ] = FALSE;

	xlow = BASEDIMENSION * ((int) (x / BASEDIMENSION));
	ylow = BASEDIMENSION * ((int) (y / BASEDIMENSION));

	for (i=xlow; i<xlow+BASEDIMENSION; i++)
		for (j=ylow; j<ylow+BASEDIMENSION; j++)
			if (board[i][j] != 0) possible[ board[i][j] ] = FALSE;
}

void print_possible(bool possible[])
{
	int i;				/* counter */

	for (i=0; i<=DIMENSION; i++)
		if (possible[i] == TRUE) printf(" %d",i);
	printf("\n");
}

int possible_count(int x, int y, bool possible[])
{
	int i;				/* counter */
	int cnt;			/* number of open squares */

	possible_values(x,y,possible);
	cnt = 0;
	for (i=0; i<=DIMENSION; i++)
		if (possible[i] == TRUE) cnt++;
	return(cnt);
}

void fill_square(int x, int y, int v)
{
	if (board[x][y] == 0)
		freecount=freecount-1;
	else
		printf("Warning: filling already filled square (%d,%d)\n",x,y);

	board[x][y] = v;
}

void free_square(int x, int y)
{
	if (board[x][y] != 0)
		freecount=freecount+1;
	else
		printf("Warning: freeing already empty square (%d,%d)\n",x,y);

	board[x][y] = 0;
}


void next_square(int *x, int *y)
{
	int i,j;			/* counters */
	int bestcnt, newcnt;		/* the best and latest square counts */
	bool doomed;			/* some empty square without moves? */

	bestcnt = DIMENSION + 1;
	doomed = FALSE;

	for (i=0; i<DIMENSION; i++) {
		for (j=0; j<DIMENSION; j++) {
			newcnt = possible_count(i,j,possible);
			if ((newcnt==0) && (board[i][j]==0))
				doomed = TRUE;
			if ((newcnt < bestcnt) && (newcnt >= 1)) {
				bestcnt = newcnt;
				*x = i;
				*y = j;
			}
		}
	}

	if (doomed) {
		*x = *y = -1;		/* initialize to non-position */
	}
}


void print_board()
{
	int i,j;			/* counters */

	printf("\n");

	for (i=0; i<DIMENSION; i++) {
		for (j=0; j<DIMENSION; j++) {
			if (board[i][j] == 0)
				printf(" ");
			else
				printf("%c",(char) '0'+board[i][j]);
			if ((j+1)%BASEDIMENSION == 0)
				printf("|");
		}
		printf("\n");
		if ((i+1)%BASEDIMENSION == 0) {
			for (j=0; j<(DIMENSION+BASEDIMENSION-1); j++)
				printf("-");
			printf("\n");
		}
	}
}
void init_board()
{
	int i,j;			/* counters */

	for (i=0; i<DIMENSION; i++)
		for (j=0; j<DIMENSION; j++)
			board[i][j] = 0;
	freecount = DIMENSION*DIMENSION;
}

void read_board()
{
	int i,j;			/* counters */
	char c;
	int value;

	init_board();

	for (i=0; i<DIMENSION; i++) {
                for (j=0; j<DIMENSION; j++) {
			scanf("%c",&c);
			value = (int) (c - '0');
			if (value != 0)
				fill_square(i,j, value);
		}
		scanf("\n"); /*newline*/
	}
}

/******************************************************************/

void process_solution(int a[], int k)
{
printf("process solution\n");
	print_board();
}

bool is_a_solution(int a[], int k, int n)
{
	if (freecount == 0) {
printf("solution found!\n");
		finished = TRUE;
		return (TRUE);
	}
	else
		return(FALSE);

}

void make_move(int a[], int k, int n)
{
printf("change board[%d][%d] to %d\n",lastx[k],lasty[k],a[k]);
	fill_square(lastx[k],lasty[k],a[k]);
print_board();

}


void unmake_move(int a[], int k, int n)
{
printf("clear board[%d][%d] to make freecount=%d\n",lastx[k],lasty[k],freecount+1);

	free_square(lastx[k],lasty[k]);
}

void construct_candidates(int a[], int k, int n, int c[], int *ncandidates)
{
	int x,y;			/* position of next move */
	int i;				/* counter */

printf("construct_candidates k=%d\n",k);
	next_square(&x,&y);		/* which square has fewest candidates */

	lastx[k] = x;			/* store our choice of where */
	lasty[k] = y;

printf("next square candidates (%d,%d) slot %d\n",x,y,k);

	*ncandidates = 0;

	if ((x<0) && (y<0))		/* error condition, no moves possible */
		return;

	possible_values(x,y,possible);
	for (i=0; i<=DIMENSION; i++)
                if (possible[i] == TRUE) {
			c[*ncandidates] = i;
			*ncandidates = *ncandidates + 1;
		}
}

void backtrack(int a[], int k, data input)
{
        int c[MAXCANDIDATES];           /* candidates for next position */
        int ncandidates;                /* next position candidate count */
        int i;                          /* counter */

        if (is_a_solution(a,k,*input))
                process_solution(a,k,input);
        else {
                k = k+1;
                construct_candidates(a,k,input,c,&ncandidates);
                for (i=0; i<ncandidates; i++) {
                        a[k] = c[i];
                        backtrack(a,k,input);
			            if (finished) return;	/* terminate early */
                }
        }
}

int main()
{
	int i,j;			/* counters */
	int a[DIMENSION*DIMENSION+1];

	read_board();
	print_board();

	for (i=0; i<DIMENSION; i++) {
		for (j=0; j<DIMENSION; j++) {
			possible_values(i,j,possible);
			printf("(%d,%d) %d open = ",i,j,
				possible_count(i,j,possible));
			print_possible(possible);
		}
	}

	next_square(&i,&j);
	printf("next square = (%d,%d) \n",i,j);

	backtrack(a,0);

    return 0;
}
