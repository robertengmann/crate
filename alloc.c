#define ALLOCSIZE 10000 /* Size of available space */

static char allocbuf[ALLOCSIZE]; /* Storage for alloc */
static char *allocp = allocbuf;  /* Next free position */

char *alloc(int n) /* Return pointer to n characters */
{
    if (allocbuf + ALLOCSIZE - allocp >= n) {
        allocp += n;
        return allocp - n; /* old p */
    } else {
        return 0;
    }
}

void afree(char *p) /* Free storage pointed to by p */
{
    if (p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}
